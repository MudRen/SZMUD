// Code of ShenZhou
// Room: tuyao.c

inherit ROOM;

void create()
{
	set("short", "��Ҥ��");
	set("long", @LONG
һ�������С����һ��֬�ۻ���Ŵ����ζ���˱Ƕ�����������Ǻ��
һ����ͷ�����ڵ��źܶ�����͵��������ı��յ�ͨ�졣�ܶഩ�����õĺ�
�ӣ�һ��§�Ź��һ�����žƺ������ڸ�̸���ۡ�һ�����ֵ���ѻһ����
���ſ��ˣ�һ�ߴ����ߴٵ�����İ鵱�͹����ǡ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"dongcheng",
	]));

        set("objects",([
        //      __DIR__"npc/xiucai" : 1,
                __DIR__"npc/jiao" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

