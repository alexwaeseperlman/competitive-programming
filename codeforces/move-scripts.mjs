#!/usr/bin/env node
import {promises as fs} from 'fs';
import * as path from 'path';

for (let dir of await fs.readdir('.')) {
	if (!(await fs.stat(dir)).isDirectory()) continue;

	const start = /^(\d+)/.exec(dir)[1];

	for (let file of await fs.readdir(dir)) {
		if (file.startsWith(start)) {
			await fs.rename(path.join(dir, file), path.join(dir, file.slice(start.length)));
		}
	}
}
