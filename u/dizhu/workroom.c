// date 29/3/2001 by spirit

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[1;32mĞ¡µØÖ÷µÄÅ©³¡[37;0m");
  set ("long", @LONG
[1;32m
ĞÓ»¨£¬ÑÌÓê£¬½­ÄÏ... ...
                     [1;36m¡¶ÌÒ»¨âÖ¸è¡·
[1;36m            ÌÒ»¨ÎëÀïÌÒ»¨âÖ£¬ÌÒ»¨âÖÀïÌÒ»¨ÏÉ¡£ 
            ÌÒ»¨ÏÉÈËÖÖÌÒÊ÷£¬ÓÖÕªÌÒ»¨»»¾ÆÇ®¡£ 
            ¾ÆĞÑÖ»ÔÚ»¨Ç°×ø£¬¾Æ×í»¹À´»¨ÏÂÃß¡£ 
            °ëĞÑ°ë×íÈÕ¸´ÈÕ£¬»¨Âä»¨¿ªÄê¸´Äê¡£ 
            µ«Ô¸ÀÏËÀ»¨¾Æ¼ä£¬²»Ô¸¾Ï¹ª³µÂíÇ°¡£ 
            ³µ³¾Âí×ã¹óÕßÈ¤£¬¾ÆÕµ»¨Ö¦Æ¶ÕßÔµ¡£ 
            Èô½«¸»¹ó±ÈÆ¶Õß£¬Ò»ÔÚÆ½µØÒ»ÔÚÌì¡£ 
            Èô½«Æ¶¼ú±È³µÂí£¬ËûµÃÇı³ÛÎÒµÃÏĞ¡£ 
            ±ğÈËĞ¦ÎÒß¯·èñ²£¬ÎÒĞ¦ËûÈË¿´²»´©¡£ 
            ²»¼ûÎåÁêºÀ½ÜÄ¹£¬ÎŞ»¨ÎŞ¾Æ³ú×÷Ìï¡£[37;0m
    baituo   °× ÍÕ É½      yuelao   ÔÂ ÀÏ Í¤       dali    ´ó Àí ¹ú
    emei     ¶ë áÒ É½      gaibang  Ø¤    °ï       beijing ±±    ¾©        
    huashan  »ª    É½      kedian   ÑïÖİ¿Íµê       xueshan Ñ©    É½            
    leitai   ÀŞ    Ì¨      murong   ¹ÃËÕÄ½Èİ       shaolin ÉÙ ÁÖ ËÂ          
    shenlong Éñ Áú µº      towiz    »á ¿Í Ìü       wiz     Î×    Ê¦            
    wudang   Îä µ± É½      wuguan   ÈªÖİÎä¹İ       wumiao  Îä    Ãí            
    xingxiu  ĞÇ ËŞ º£      xuanjie  Ğş ½Ù ½Ì       taohua  ÌÒ    »¨
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/shaolin/npc/mu-ren" : 1,
]));
  set("exits", ([ /* sizeof() == 23 */
  "wudang" : "/d/wudang/sanqingdian",
  "xueshan" : "/d/xueshan/guangchang",
  "wumiao" : "/d/city/wumiao",
  "wuguan" : "/d/quanzhou/qianting",
  "wiz" : "/d/wizard/wizard_room",
  "towiz" : "/d/wizard/guest_room",
  "murong" : "/d/murong/qing4",
  "huashan" : "/d/huashan/pianting",
  "taohua" : "/d/taohua/jingshe",
  "shenlong" : "/d/shenlong/tingkou",
  "leitai" : "/u/xuy/bwdh/leitai",
  "xingxiu" : "/d/xingxiu/xxh2",
  "shaolin" : "/d/shaolin/guangchang1",
  "kedian" : "/d/city/kedian",
  "gaibang" : "/d/gaibang/undertre",
  "xuanjie" : "/d/qilian/datang",
  "yuelao" : "/d/city/yuelao",
  "emei" : "/d/emei/hz_guangchang",
  "guiyun" : "/d/taihu/qianyuan",
  "baituo" : "/d/xingxiu/btyard",
  "lingjiu" : "/d/lingjiu/main-22",
  "dali" : "/d/dali/wangfu1",
  "center" : "/d/wizard/center",
  "beijing" : "/d/beijing/kedian",
]));
  set("cost", 1);
  call_other("/clone/board/dizhu_b", "???"); 
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me))
		return notify_fail("ÁáÁáµ²ÔÚÄãÃæÇ°£¬¹§ÉíËµµÀ£º¡°·Ç³£±§Ç¸£¬Äú²»ÄÜµ½ÄÇ¶ùÈ¥¡£¡±\n");

	return ::valid_leave(me, dir);
}

int init()
{
        add_action("do_leave", "leave");
}

int do_leave()
{
	object me = this_player();
        tell_room(environment(me),
        "Ìì¿ÕÍ»È»·¢³öÀ×Ãù£¬"+(string)me->query("name")+"µôÂäµ½ÁË·²¼ä¡£\n",
        ({this_player(), me}));
        me->move("/d/city/wumiao");
       message("vision", me->name() + "Í»È»´Ó¿ÕÖĞµôÁËÏÂÀ´£¬½á½áÊµÊµË¤ÁË¸öÆ¨¶Õ¡£\n",
                environment(me), ({me}) );
	return 1;
}
