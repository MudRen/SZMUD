//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","大雁塔");
	set("long",@LONG
这里就是著名的大雁塔，游客们都在欣赏这里的风景。边上有几个小贩正
在卖猕猴桃，喊价声连连传来。大雁塔为一座七层方形塔，塔身十分雄伟，底
座宽大，造型简洁庄严神秘。方塔底座有门，门楣上有石刻画。
LONG
	);
	set("exits",([

		"southwest" : __DIR__"huadian",
		"south" : __DIR__"dadao",
	]));

	setup();
}
