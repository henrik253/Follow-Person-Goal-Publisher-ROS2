# ROS2 Workspace: workspace
GIT: 
	Submodules
		git submodules add -b branchname url 
		git submodules add url 

	Falls gleiche Submodules bereits gestaged sind dann nachschauen mit: 
		git ls-files --stage projectname 
	verwerfen mittels: 
		git rm --cached projectname

	falls submodules submodules besitzen: 
		git submodules update --init --recursive 

BASH: 
	export varName="Value der localen Env Variable" 
	echo $varName // gibt den Wert aus 
	. // ist das gleiche wie source
	source install/local_setup.bash // sourced skript, also führt es in der eigenen Shell aus

	Skripting 
	chmod +x script.sh // Skript ausführbar machne 
	./script.sh 


OUSTER OS1 
	Ouster mit Netzwerk verbinden 
	Im Browser mittels url suchen rbt-10b.lri.hochschule-trier.de
	Hostname in driver params eintragen 
	colcon build --symlink-install
	. install/local_setup.bash // sourcing des skriptes in eigener Shell (nicht in neuer) z.B. Umgebungsvariablen in der Shell zu ändern
