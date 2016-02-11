# experiment w/ conda packaging a python wheel
# python setup.py install
python setup.py bdist_wheel
pip install --no-index --find-link=dist/ polygon
