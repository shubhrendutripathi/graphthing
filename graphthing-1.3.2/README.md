

--------------------------------------------------------------------------
# GraphThing 1.3.2 
## port to wxWidgets 3.0 by Shubhrendu Tripathi
--------------------------------------------------------------------------

This is a port of GraphThing 1.3.2 to wxWidgets 3.0. I have successfully compiled this on Ubuntu 16.04 Xenial 
using dependencies from the standard Ubuntu repository.









ORIGINAL README below ->

GraphThing 1.3.2			(c) 2001-2006 David Symonds

(See bottom of this file for copyright notice)

This is GraphThing, a graph theory tool, written by David Symonds. You can
email me at <dsymonds@gmail.com>.

INSTALLATION

	GraphThing requires wxWidgets 2.6.1 (or later).
		[http://www.wxwidgets.org]
	To build GraphThing, you'll also need GNU make, bison and flex.

	Run the following commands:

	* ./configure
	* make			[ or "gmake" ]

	and optionally:

	* make install		[ as root ]

	If you don't run "make install", you can execute the binary from
	the src/ directory.

	It is not uncommon for the configure script to be unable to find your
	wxWidgets installation. Pass it the full path to the wx-config script,
	as in:

		./configure --with-wx-config=/usr/local/bin/wx-config

	The configuration script takes all the usual options. Use
		./configure --help
	for a complete list. If you want to use an alternative C++ compiler,
	run the command
		CXX=/usr/g++295/bin/g++ ./configure
	where "/usr/g++295/bin/g++" is the command in question.

OPERATION

	Most of the operations are intuitive, but there are a couple of
	confusing things:

	In Vertex Mode:
		* To create a vertex: Double click on a blank area
		* To move a vertex: Click and drag it
		* To select multiple vertices: Hold shift while clicking
		* To modify vertex properties: Double click on the vertex
		* To delete a vertex: Select it and press the Delete key
	In Edge Mode:
		* To create an edge: Click on first vertex, then click on
					second vertex
		* To select multiple edges: Hold shift while clicking
		* To modify edge properties: Double click on the edge
		* To delete an edge: Select it and press the Delete key

INTERNATIONALISATION

	GraphThing includes some translations of the phrases it uses. The
	following languages (with their country codes) are listed below.

		Catalan (ca)
		Chinese (Simplified) (zh)
		French (fr)
		German (de)
		Italian (it)
		Romanian (ro)
		Spanish (es)
		Swedish Chef (sv_CK)

	To select a language, GraphThing inspects the following environment
	variables in order. The first one that is recognised as a valid
	language code is selected as the language to use.

		LANGUAGE
		LC_ALL
		LANG

	So, if you want GraphThing to be in German, simply start it with the
	command (in bash):

		LANGUAGE=de gt

--------------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
--------------------------------------------------------------------------
