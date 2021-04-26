// /adm/daemons/named.c
// ĞÕÃûÉú³ÉÆ÷
// create by akuma@mudnow
// 2000/9/26
// ver 1.0

#include <ansi.h>

string *name_xing=({
		"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","ËÎ","Â¬","¹«Ëï","¹Ø","ÁÖ","ºôÑÓ",
		"Ñî","Âí","Å£","ÂÀ","Ç×","»¨","²ñ","Öì","Â³","Îä","ÕÅ","¶­","Ğì","Ë÷","´÷",
		"Ê·","Áõ","ÄÂ","À×","Èî","Ñà","½â","»Æ","µ¥","º«","ºÂ","Åí","Îº","Æë","Ïô",
		"Å·Ñô","µË","Áè","°²","¹ù","½¯","Ñ¦","¸ß","±«","¿×","½ğ","Ïî","Í¯","ÃÏ",
		"ºî","³Â","Áº","Ö£","¹¨","ÌÕ","·¶","°ü","·®","Ê¯","Ê±","¶Î","×ó","ĞÁ","ÓÚ",
		"Óà","Î¾³Ù","²Ü","¼§","´Ş","¼Ö","¹Ë","¶Å","Ã«","ºÎ","·Ñ","Ê©","ÅË","ÑÏ",
		"Ó÷","·½","ÑÕ","ÌÆ","Á®","µ¥","»ô","·ë","·â","ÉÏ¹Ù","Ë¾Âí","×ó","¸µ","ÎÅ",
		"¾£","ĞÌ","ÁÖ","Áîºü","¶À¹Â","ÎÅÈË","ÄÏ¹¬","Éê","·®","Î£","Ñô","¿×","ÔÀ","×Ş"
		});
string *pinyin_xing=({
		"zhao","qian","sun","li","zhou","wu","zheng","wang","song","lu","gongsun","guan","lin","huyan",
		"yang","ma","niu","lv","qin","hua","chai","zhu","lu","wu","zhang","dong","xu","suo","dai",
		"shi","liu","mu","lei","ruan","yan","xie","huang","shan","han","hao","peng","wei","qi","xiao",
		"ouyang","deng","ling","an","guo","jiang","xue","gao","bao","kong","jin","xiang","tong","meng",
		"hou","chen","liang","zheng","gong","tao","fan","bao","fan","shi","shi","duan","zuo","xin","yu",
		"yu","yuchi","cao","ji","cui","jia","gu","du","mao","he","fei","shi","pan","yan",
		"yu","fang","yan","tang","lian","shan","huo","feng","feng","shangguan","sima","zuo","fu","wen",
		"jing","xing","lin","linghu","dugu","wenren","nangong","shen","fan","wei","yang","kong","yue","zou"
		});

string *name_ming1=({
		"Ğ¡",
		"´ó","¶ş","Èı","ËÄ","Îå","Áù","Æß","°Ë","¾Å","Ê®",
		"°¢",
		"ÍÅ",
		"Éú",
		"°Ù",
		"Ìú","½ğ","Ë®","Ä¾","»ğ",
		"³£","¾Ã","ÓĞ","ÎŞ","¶à","ÉÙ",
		"Ã÷","¹ó","»¢","±ª","Çì","Ë³","ÔÆ","·É","¼á","Ïè","³¬",
		"Îª",
		"Ê¤","ºá","Æ½","ºë","Ìì","±£","Èº","Ìï",
		"Åô","Áú","çû","ÂÚ","Óğ","¿Â","Éú","ÁÁ","ÀË","ÌÎ","²¨","ÂÍ","½Ü","½£",
		"Ó¢","ĞÛ","Ç±","Ø·","ÔÆ","ÈÕ","ÃÍ","Íş","Áî","ÔÆ","·å","²©","ÖÇ","Ö¾",
		"Ì´","óÌ","Ãá","¾´","ÔØ","Â´","¸è","ßà","Ğş","Õ÷","Ğù","¶«","±ë","ò°",
		"¾¢","½İ","ÓÀ","º£","¾°","º½","Ïş","³É","êÉ","çâ","Ïæ","ºê","Ñ©",
		"ÖĞ","Ë¾","¶¦","ÖÓ","°Ø","Ó¯","Ä½","Óî","ÔÆ","Ìì","Á¢",
		"·É",
		});
string *pinyin_ming1=({
		"xiao",
		"da","er","san","si","wu","liu","qi","ba","jiu","shi",
		"a",
		"tuan",
		"sheng",
		"bai",
		"tie","jin","shui","mu","huo",
		"chang","jiu","you","wu","duo","shao",
		"ming","gui","hu","bao","qing","shun","yun","fei","jian","xiang","chao",
		"wei",
		"sheng","heng","ping","hong","tian","bao","qun","tian",
		"peng","long","kun","guan","yu","ke","sheng","liang","lang","tao","bo","luan","jie","jian",
		"ying","xing","qian","yin","yun","ri","meng","wei","ling","yun","feng","bo","zhi","zhi",
		"tan","qiong","mian","jing","zai","lu","ge","kuai","xuan","zheng","xuan","dong","biao","qiu",
		"jing","jie","yong","hai","jing","hang","xiao","cheng","sheng","hui","xiang","hong","xue",
		"zhong","si","ding","zhong","bai","ying","mu","yu","yun","tian","li",
		"fei",
		});


string *name_ming2=({
		"¶ş","Èı","ËÄ","Îå","Áù","Æß","°Ë","¾Å",
		"ÁÖ","İ·","Éğ","Ë¼","Ä½","ÓÀ","çß","ìè","ºÛ","ãÔ","Äı","ÒË","ÒÇ","Òà","Òí",
		"ÀÉ",
		"¶ù",
		"Íò",
		"»¢","Å£","±ª",
		"×Ó",
		"Åô","Áú","çû","ÂÚ","Óğ","¿Â","Éú","ÁÁ","ÀË","ÌÎ","²¨","ÂÍ","½Ü","½£",
		"¾¢","½İ","ÓÀ","º£","¾°","º½","Ïş","³É","êÉ","ì¿","Ïæ","ºê","Ñ©",
		"¸»","¹ó","¸£",
		"Äê","ÔÂ","ÈÕ",
		"Éú","Ìì","Ãñ","Ã÷",
		"Çä","Áú","¿µ","Ë³","²Ê","·ç","Óê","ÔÆ",
		"¿µ",
		"»ª","Ó±",
		"³å","Áˆ",
		"Ã·",
		});
string *pinyin_ming2=({
		"er","san","si","wu","liu","qi","ba","jiu",
		"lin","shen","shen","si","mu","yong","yong","hu","hen","hun","ning","yi","yi","yi","yi",
		"lang",
		"er",
		"wan",
		"hu","niu","bao",
		"zi",
		"peng","long","kun","guan","yu","ke","sheng","liang","lang","tao","bo","luan","jie","jian",
		"jing","jie","yong","hai","jing","hang","xiao","cheng","sheng","hui","xiang","hong","xue",
		"fu","gui","fu",
		"nian","yue","ri",
		"sheng","tian","min","ming",
		"qing","long","kang","shun","cai","feng","yu","yun",
		"kang",
		"hua","ying",
		"chong","chong",
		"mei",
		});

string *nick_first=({
		HIB"ÄÏº£"NOR,HIY"Æ½Ô­"NOR,HIW"ÁÉ¶«"NOR,HIG"´¨Î÷"NOR,RED"Æ½Ñô"NOR,WHT"ÌìÍâ"NOR,BLU"¶À¹Â"NOR,HIW"Æ®Ñ©"NOR,YEL"Çó°Ü"NOR,GRN"ÎŞĞÄ"NOR,MAG"ºì·Û"NOR,RED"Ï¦Ñô"NOR,
	GRN"½­ÄÏ"NOR,});

string *nick_second=({MAG"°Ô"NOR,CYN"µ¶"NOR,RED"½£"NOR,WHT"Ç¹"NOR,BLU"±Ş"NOR,YEL"Ë÷"NOR,HIR"ºì"NOR,CYN"½¿"NOR,HIB"»¢"NOR,HIY"±ª"NOR,HIR"ÀÏÈË"NOR,HIG"¿Í"NOR,WHT"ÏÀ"NOR,BLU"Áú"NOR,});

string create_name()
{
	string name,pinyin_name;
	int xing,ming1,ming2,yes1;
	xing=random(sizeof(name_xing));
	ming1=random(sizeof(name_ming1));
	ming2=random(sizeof(name_ming2));
	yes1=random(3);
	
	name = name_xing[xing];
	name+= yes1?name_ming1[ming1]:"";
	name+= name_ming2[ming2];
	
	pinyin_name = pinyin_xing[xing];
	pinyin_name+= " ";
	pinyin_name+= yes1?pinyin_ming1[ming1]:"";
	pinyin_name+= pinyin_ming2[ming2];
	
	return(sprintf("%s@%s",name,pinyin_name));
}

string create_nick()
{
	string nick1,nick2;
	nick1=nick_first[random(sizeof(nick_first))];
	nick2=nick_second[random(sizeof(nick_second))];
	if(random(5)>3)
		return nick1+"Ò»"+nick2;
	else
		return nick1+nick2;
}
