// Code of ShenZhou
// Room: /d/dali/wangfu8.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
进入堂，抬头迎面先看见一个赤金九龙青地大匾，上面写著
斗大三个字，是：「荣禧堂」；又有「万机宸翰」之宝。大紫檀
雕螭案(desk)上设著三尺来高青绿古鼎，悬著待漏随朝墨龙大画，
一边是金锥彝，一边是玻璃盒，底下两溜十六张紫檀交椅，又有
一副对联，乃乌木联牌，镶著凿银的字迹，道：
      座上珠玑昭日月，堂前黼黻焕烟霞。
LONG
	);
	set("cost", 1);
	set("wangfu", 1);

	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"wangfu11",
		]));
	set("objects", ([
		"/kungfu/class/dali/zhengchun" : 1,
		]));
	set ("item_desc", ([
		"desk" : "桌上摆放了好几本书，既有佛学经文，也有道家典籍，还有一本易经。\n"
		])  ) ;

	set("no_clean_up", 0);

	setup();
}

