// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
�����������ѡ��������������֮������·Ӣ�����ܼ�ѹȺ�ۣ�
�������������ʶ�������������Ϊͳ����ԭ���ֵ����䡣��̨��
�ڷ��ź����������������ڴ��������¡�̨�ϸ߸�����һ���죬
���飺�����е� �ĸ����֡� �������Ҹ���������λ������ʿ����
�߶�����һ���Ż�Ƥ���Σ�ʱ��������ǰ������ǰ���μ�������
LONG
	);

	set("exits", ([
		"down" : __DIR__"yuhuang",
		"southwest" : __DIR__"fengchansw",
		"southeast" : __DIR__"fengchanse",
		"northwest" : __DIR__"fengchannw",
		"northeast" : __DIR__"fengchanne",
	]));

	set("objects",([
		"/clone/npc/meng-zhu" : 1,
		__DIR__"npc/wei-shi1" : 4,
	]));

        set("no_clean_up", 1);
	set("outdoors", "taishan");

	set("cost", 2);
	setup();
}

void init()
{
	object ob;	

	if( objectp( ob = present("mengzhu 2", this_object()) ) )
	destruct(ob);
}



