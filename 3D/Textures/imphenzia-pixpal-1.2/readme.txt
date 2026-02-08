Imphenzia PixPal Palette Version 1.2


*** LICENSE *******************************************************************

CC0 - Creative Commons 0 - Public Domain

CC0 License Covers TEXTURES, MATERIALS and SHADERS:

 * ImphenziaPixPal_BaseColor.png
 * ImphenziaPixPal_Emission.png
 * ImphenziaPixPal_Attributes.png
 * Blender Imphenzia PixPal Material
 * ImphenziaPixPal_URP.mat (Unity Material)
 * ImphenziaPixPal_URP.shadergraph (Unity Shader Graph)
 * Imphenzia-PixPal.uasset (Unreal Engine Material)
 * ImphenziaPixPal.tres (Godot Material)

!! CC0 License _DOES NOT_ cover the SHOWCASE SAMPLE ASSETS !!

The showcase sample assets are are NOT covered by the license.
The showcase sample assets are copyright by Imphenzia Pty Ltd. 
You can purchase a license (very cheap) to use the low poly characters and
furniture which are included in larger asset packs at https://www.imphenzia.com


*** CONTENTS ******************************************************************

Textures\ImphenziaPixPal_BaseColor.png
 - the texture used for base colors.
 
Textures\ImphenziaPixPal_Emission.png 
 - the texture used for emission.
 
Textures\ImphenziaPixPal_Attributes.png
 - the texture used to control metallic, roughness and animation.

Blender\Imphenzia-PixPal.blend
 - A Blender 4.3 file with the textures, material, and showcase sample assets.
 
 Blender\Imphenzia-PixPal-PreBlender_4_2.blend
 - A legacy blender file for earlier versions of blender before Bloom was removed and changed
   to a compositor glare feature.

Game_Engines\Unity_Packages\Imphenzia_PixPal_Unity_6.unitypackage
 - a Unity 6 package containing only the textures, and material with shader graph.

Game_Engines\Unity_Packages\Imphenzia_PixPal_Unity_6_WithShowcase.unitypackage
 - a Unity 6 package containing textures, material, shader graph and showcase sample assets.
 
Game_Engines\Unity_Project\Imphenzia_PixPal_Unity_6_URP_Project.zip
 - a Unity 6 URP project with textures, material, and showcase sample assets.
 
Game_Engines\Unreal_Engine_Project\Imphenzia_PixPal_UnrealEngine_5_5_1_Project.zip
 - an Unreal Engine 5.5.1 project with  textures, material, and showcase sample assets.
 
Game_Engines\Godot\Imphenzia_PixPal_Godot_4_3_Project.zip
 - a Godot 4.3 project with textures, material, and showcase sample assets.


*** REFLECTIVE SURFACES (METAL & MIRROR) **************************************

The materials in the Blender file, the Unity project, the Unreal Engine
project and the Godot project have the correct texture settings, material and
shaders for texture quality, emission, to work.

Note that Unity URP and Godot do not support reflection as good as Blender and
Unreal Engine.


*** VERY IMPORTANT INFORMATION ************************************************

If you create your own materials, take the following into consideration:

!! USE NEAREST NEIGHBOR / CLOSEST / POINT FILTERING !!

If you use the textures in a game engine, make sure you set the filtering to
Nearest Neighbor or Closest (it should NOT be bilinear or bicubic - it smears
the textures since the colors are only one pixel in width).

!! DO NOT USE TEXTURE COMPRESSION !!

If you use compression on the textures in a game engine, the colors will be
incorrect. Disable any form of compression on the texture - it needs to be
pixel perfect.

!! DO NOT USE MIPMAPS !!

The pixel perfect textures are already as small as they can be so it is
advised to disable mipmapping, especially in Unreal Engine where Nanite
can create artifacts around edges of low poly objects.

!! USE WRAP / REPEAT - NOT CLAMP !!

Animations rely on UVs wrapping or repeating at the edges, otherwise the
animated colors will stop as time goes beyond one second. 


*** VERSION HISTORY ***********************************************************

1.2 Updated projects to Blender 4.3, Unity 6.0, Unreal Engine 5.5.1, Godot 4.3
    Added more sample assets (furniture, character, and car)

1.1 Added Godot 4.1 project (thanks Flynsarmy!)
    Updated Unreal Engine project to Unreal Engine 5.3
	Added emission strength parameter in game engine projects to control bloom.
	Changed Unreal Engine texture disable mipmap which caused Nanite artifacts.

1.0 Initial Release


*** PORTS *********************************************************************

babylon.js by - user inteja 
https://forum.babylonjs.com/t/imphenzia-pixpal-palette-texture-node-pbr-material-example/56066


You are welcome to port the Imphenzia PixPal palette textures, materials, and
shaders to any game engine or software. 

!! You may also include some or all showcase sample assets in such ports but
you must then also include this readme.txt file !!


*** THANK YOU *****************************************************************

Please subscribe to my YouTube channel, https://www.youtube.com/imphenzia

Enjoy the rewards as a patron on https://www.patreon.com/imphenzia

Check out my low poly assets on https://www.imphenzia.com/assets
