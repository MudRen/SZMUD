//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","����ɽ���");
	set("long",@LONG
��ݵĴ�����д�ż����Ծ�����[����ɽ���]��ׯ�����ɡ�Ļ�����˰�ʦ
���˺ܶ࣬���ŵ���������ͷ�ߴ��ʯʨ�ӣ���ǰ�߾͵���ݵĴ�Ժ�ˡ�
LONG
	);
	set("exits",([
                "east" : __DIR__"sroad2",
		"west" : __DIR__"wgdayuan",
	]));
          set("objects", ([
          __DIR__"npc/mending" : 2,
          ]));

          set("cost", 1);

	setup();
}
