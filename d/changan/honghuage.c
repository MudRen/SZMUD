//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�컨��");
	set("long",@LONG
������һЩ�޼ҿɹ飬��������������Ů�ӳ����Լ�����ĵط�����ʵ��
����¥���컨������Ǹ�����ƶ��Ů�ӵĵط�����֪���ã���ɷ糾Ů�ӳ�
��ɫ��ĳ���������Ů��������Ц�����һ�����ҹ��Ӿ��ƣ�����ү���ķ�ͷ
���������һ��Ż�¡�
LONG
	);
	set("exits",([

		"north" : __DIR__"eroad3",
	]));

     set("objects", ([
          __DIR__"npc/guinu" : 1,
     ]));
	setup();
}
