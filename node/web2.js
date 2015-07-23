var http = require('http'), fs = require('fs');

function handle_list_album(callback){
	fs.readdir('album', function(err, files){
			if(err){
			callback(err);
			return;
			}
			var dirs = [];
			
			(function iterator(index){
				if(index == files.length){
					callback(dirs);
				}
				fs.stat('album/'+files[index], function(err, stats){
					if (err) {
						callback(err);
						return;
					}
					if(stats.isDirectory()){
						dirs.push(files[index]);
					}
					iterator(index+1);
				})
			})(0);
			
			//callback(null, dirs);
		}
	)
}

function handle_request(req, res){
	console.log('INCOMING REQUEST '+req.method+" url is "+req.url);
	if(req.url == '/album.json'){
		handle_list_album(req, res);
	} else if (req.url.substr(0,7) == '/album' && req.url.substr(req.url.lenght - 5) == '.json'){
		handle_get_album(req, res);
	} else {
		send_failure(res, 404, invalid_resource());
	}
	//load_album(function (err, files){
	if(err){
	res.writeHead(503, {"Content-Type": "application/json"});
	res.end(JSON.stringify(err) + "\n");
	return;
	}
	var out = { error: null,
data: { albums: files }};
res.writeHead(200, {"Content-Type": "application/json"});
res.end(JSON.stringify(out) + "\n");
	})
}

var s = http.createServer(handle_request);

s.listen(8080);
