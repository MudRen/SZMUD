// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "�ɰ���");
	set("long", @LONG
�����ɰ���ÿ����ľ֮��������£�֦��������ӳ��̧ͷ��ȥ�������Ҷ������
�أ����Ʊ��գ�������ȴ���߳��㣬�˺����֡��治֪����Ȼ���ͣ���������ż�á�
����һ��С���������У�ָ�򱱷����������ƺ���һ�����֡�
LONG
	);
	 set("exits", ([
                "north" : __DIR__"hanbi",
                "south" : __DIR__"songlin2",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
