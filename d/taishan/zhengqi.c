// Code of ShenZhou
// Room: /d/taishan/zhengqi.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƿ���̨�ұߵ��������������˷���ʹ��ƽʱ����ɽʱ��
ͨ�����������ﴦ�����ֹ������������з��Űѻ�Ƥ�Σ�����ʹ��
���������濪���������Ҹ������ż�λ������ʿ������ȥɱ����
�ڣ�������Ȼ�������⡣
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"fengchannw",
		"southeast" : __DIR__"fengchansw",
	]));

	set("objects",([
		"/clone/npc/fa-e" : 1,
		__DIR__"npc/wei-shi2" : 3,
	]));

        set("no_clean_up", 1);

	set("cost", 2);
	setup();
}

void init()
{
	object ob;	

	if( objectp( ob = present("fae 2", this_object()) ) )
	destruct(ob);
}

