# yamlamldingdong

> This is an example / practice repository for initial development
> and review of code for **part** of [Calamares Issue #1036][radiobutton],
> namely the conversion of a configuration file into C++ structures.

## YAML design

Calamares takes configuration as a YAML file. The YAML file is
parsed by libyaml-cpp, then converted into a QVariantMap, and
then that QVariantMap is taken apart by C++ classes into 
convenient structures for the functionality at hand.

See `examples/yaml.conf` for an example YAML file; other files
in that directory provide additional example or testing
material.

## Functionality

Function `setConfigurationMap()` should take apart the
`QVariantMap` that is passed to it and transform into suitable
C++ data objects. 

Reflecting the structure of the YAML, there are two classes
to create (here, bottom-up):

 - `ChoiceItem` which holds data about a single choice:
   its name, icon, etc.
 - `ChoiceGroup` which holds nothing more than a list of
   `ChoiceItem`s, as well as a (user-visible) title for
   the group as a whole.

For bonus points, the two classes can have a `makeWidget()` method
which creates a widget for that single choice (this would be a radio
button with an icon and some text, probably) or group (a box with
title and nested widgets for each choice).

[radiobutton] https://github.com/calamares/calamares/issues/1036
