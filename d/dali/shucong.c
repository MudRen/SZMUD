// Code of ShenZhou
// Room: /dali/wls9.c
// AceP
// The path from ChaDao to Wu Liang Shan :
// se; w; s; n; ne; w; sw; n; 9: #9, ne; sw; nw; e; s; w; sw; n; w;

inherit ROOM;

int do_sigh();
int do_eat(string);

void create()
{
	set("short", "树丛深处");
	set("long", @LONG
这里是树丛的深处。你四周都是荆棘杂木，一点点光线从密林的缝隙中透过来，
所以这里还勉强可以见物。一些毒蛇、蜈蚣、蝎子等毒虫四处爬走。
LONG
	);

	set("exits", ([
		"out" : __DIR__"wls9",
	]));

	set("cost", 2);
        set("outdoors", "dali");
	setup();
}

void init()
{
	add_action("do_sigh", "sigh");
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me,hama;
	me=this_player();

	if (arg=="hama" && (hama=present("hama", environment(me)))) {
		if (getuid(me)==query("who")) {
			write(
"看到许多毒虫被这莽牯朱蛤口中红烟一喷，挣扎不了几下就死了，你吓得舌头都吐出来了。\n"
"你呆着不敢动，不料这蛤蟆误以为你的舌头是什么毒虫，跳过来一扑，钻进了你的口中！\n"
"“咕咚”一下莽牯朱蛤被你吞进了肚子里！\n");
			me->set("ate_hama");
			destruct(hama);
		}
		else {
			write(
"你看这莽牯朱蛤实在奇特，动了食欲，伸手想捉住它尝尝鲜，不料莽牯朱蛤对你张口一喷，\n"
"你被一股红烟一熏，顿时全身麻木，“咕咚”一下就摔倒在地！\n");
			me->die();
		}
		return 1;
	}
	return 0;
}

int do_sigh()
{
	object me;
	me=this_player();
	add("sighed",1);

	if (random(3)==3 && query("sighed")==1) {
		set("who", getuid(me));
		delete("sighed");
		remove_call_out("hamaout");
		call_out("hamaout", 300);
	}
	return 0;
}

void hamaout()
{
	object hama;
	write("“呱叽，呱叽，呱叽”随着几声非常大的蛤蟆叫声，你四周的毒虫四散奔逃，\n"
"一只拳头大小的红蛤蟆从草丛底下跳了出来\n");
	hama=new(__DIR__"npc/hama");
	hama->move(environment());
}
