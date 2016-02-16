$(document).ready(function() {

function getLeftSpeed()
{
	$('#left-speed').val(NetworkTables.getValue('/SmartDashboard/leftSpeed', 0.0))
}

function getRightSpeed()
{
	$('#right-speed').val(NetworkTables.getValue('/SmartDashboard/rightSpeed', 0.0))
	console.log($('#right-speed').val())
}

function getLoadSpeed()
{
	$('#load-speed').val(NetworkTables.getValue('/SmartDashboard/loadSpeed',0.0))
}

function getShootSpeed()
{
	$('#shoot-speed').val(NetworkTables.getValue('/SmartDashboard/shootSpeed',0.0))
}

setInterval(function() {
	getLeftSpeed();
	getRightSpeed();
	getLoadSpeed();
	getShootSpeed();
}, 20);
});