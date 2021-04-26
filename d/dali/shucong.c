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
	set("short", "�����");
	set("long", @LONG
���������Ե���������ܶ��Ǿ�����ľ��һ�����ߴ����ֵķ�϶��͸������
�������ﻹ��ǿ���Լ��һЩ���ߡ���򼡢Ы�ӵȶ����Ĵ����ߡ�
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
"������඾�汻��ç�������к���һ�磬�������˼��¾����ˣ����ŵ���ͷ���³����ˡ�\n"
"����Ų��Ҷ���������������Ϊ�����ͷ��ʲô���棬������һ�ˣ��������Ŀ��У�\n"
"�����ˡ�һ��ç��������̽��˶����\n");
			me->set("ate_hama");
			destruct(hama);
		}
		else {
			write(
"�㿴��ç�����ʵ�����أ�����ʳ����������׽ס�������ʣ�����ç���������ſ�һ�磬\n"
"�㱻һ�ɺ���һѬ����ʱȫ����ľ�������ˡ�һ�¾�ˤ���ڵأ�\n");
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
	write("����ߴ����ߴ����ߴ�����ż����ǳ���ĸ������������ܵĶ�����ɢ���ӣ�\n"
"һֻȭͷ��С�ĺ���ӲݴԵ������˳���\n");
	hama=new(__DIR__"npc/hama");
	hama->move(environment());
}
