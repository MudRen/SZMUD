//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","��Ӫ����");
	set("long",@LONG
������ǳ����ǵı�Ӫ�����ˣ��ٱ������ţ��������㿴������������ס�ˣ�
�������һֻ����Ҳ�����ȥ�����������Ҫ�ķ��ˡ���ˣ���������Ĺٱ�
�����а����и��
LONG
	);
	set("exits",([
                "east" : __DIR__"sroad3",
		"west" : __DIR__"bingying",
	]));
        set("no_fight",1);
	set("objects",([
               
                 __DIR__"npc/bing":2,
        ]));

	setup();
}
