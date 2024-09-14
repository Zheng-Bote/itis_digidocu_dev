import './itis-menu/ItisMenu.js';
import './itis-menusub/ItisMenuSub.js';
import './itis-footer/ItisFooter.js';
import './popup-info/PopUpInfo.js';

// ###
window.onload = function () 
{
 /*
    window.addEventListener('contextmenu', function (e) 
    {
        console.log('context menu disabled');
        e.preventDefault();
    }, false);
*/

    try 
    {
        console.log("call local function");
        doLocal();
    }
    catch(err)
    {
        console.log("local function error: " + err);
    }
}


