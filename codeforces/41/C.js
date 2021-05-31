const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
	terminal: false
});

const parsed = line => {
	line = line[0] + line.slice(1, -1).replaceAll('dot', '.') + line.slice(-1);
	line = line.split('at');
	while (true) {
		end = line[line.length - 1];
		if (end.split('.').length == 2 && end[0] == '.' || end.split('.').length == 1) {
			line[line.length - 2] += 'at' + line[line.length - 1];
			line = line.slice(0, -1);
		}
		else break;
	}
	return line.slice(0, -1).join('at') + '@' + line[line.length - 1];
}

rl.on('line', (line) => {
	console.log(parsed(line));
	process.exit(0);
});
