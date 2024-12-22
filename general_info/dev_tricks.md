## python environments

### venv

- bundled automatically with python

a) cd to your project

``cd how_to_not_be_chot/``

b) create new virtual environment and call it venv

``python -m venv venv``

- this creates a folder called venv

c) activate the virtual environment

``source venv/bin/activate``

- you should see a (venv) now in your terminal promp indicating that the environment is active

d) install what u need

``pip install pygame``

e) deactivate the virtual environment


requirements.txt

- write installed packages to file:

``pip freeze > requirements.txt``

- install from txt

``pip install -r requirements.txt``
