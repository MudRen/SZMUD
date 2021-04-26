// Code of ShenZhou
// wofang1.c

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这是大理国男子官员的卧室，武将及以下级别的官员可在此休息
睡觉，几张张收拾得干干净净的床铺沿墙摆了一圈。
LONG );

	set("exits", ([
		"east" : __DIR__"diziarea.c",
		]));

	set("sleep_room", 1);
	set("no_fight", 1);
	setup();
}

void init()
{
/*	object ob=this_player();

	if (!wizardp(ob) && ob->query("family/family_name") != "大理段家") {
		message_vision("几个王府家丁冲了进来，大声嚷道：“$N你不是大理的人，怎么闯到这里来了？快滚出去！\n",ob);
		if (!userp(ob)) {
			message_vision("说着就蜂拥而上向$N乱棍打去。\n",ob);
			ob->unconcious();
		}
		remove_call_out("kickout");
		call_out("kickout", 1, ob);
	}
*/
	add_action("do_get", "get");
}
/*
int kickout(object ob)
{
	if (!present(ob,find_object("/d/dali/wofang1.c"))) {
		return 1;
	}
	message_vision("一群武士蜂拥而上把$N乱棍轰了出去。\n",ob);
	ob->move("/d/dali/taihejie5");
	message("vision","只听“乒”地一声，"+ob->query("name")+"从王府里被人乱棍打了出来。\n", environment(ob), ob);
	if (!userp(ob)) {
		ob->revive();
		ob->set("qi",ob->query("eff_qi"));
		ob->set("jing",ob->query("eff_jing"));
		ob->set("jingli",ob->query("max_jingli"));
	}
	return 1;
}
*/

int do_get(string arg)  
{
	string a,b,c;
	object obj;

	if ( arg && objectp(obj = present(arg, environment(this_player())))
        && obj->is_character() ) {
		write("你不能搬动玩家的身体。\n");
		return 1;
	}
	if (!arg || sscanf(arg, "%s %s %s", a, b, c) != 3 )
		return 0;
	if ( b != "from" ) return 0;
	if ( objectp(obj = present(c, environment(this_player())))
        && obj->is_character() ) {
		write("你不能从睡着了的玩家身上偷东西。\n");
		return 1;
	}
	return 0;
} 


