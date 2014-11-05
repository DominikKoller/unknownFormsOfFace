<!doctype html>
<html>
	<head>
		<meta charset="utf-8" />
		<title>unknownFormsOfFace</title>
	</head>
	<body>
		<canvas id="canvas" width="400", height="200" style="border: 1px solid grey" onclick="toggleSearchForFace()"></canvas>
		<p>Click into the canvas above to toggle searching for faces.</p>
		<p>Note that face detection (and anything else too) in the browser is comparably very slow, so it might take ages to find a face.</p>
		<p>I never did find one, so I'd recommend running the C++ or Processing/Java version.</p>
		<p>When a face is found, the process is stopped and you can save the image per rightclick - save image. <br> 
		When you (left)click in the canvas again, it will search for another face and discard the image.</p>

		<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
		<script src="jquery.facedetection.min.js"></script>

		<script src="unknownFormsOfFace.js"></script>
	</body>
</html>