//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�ϰ���");
	set("long",@LONG
�ϰ��Ž䱸ɭ�ϣ�һЩ�ٱ����ڼ��������ǵ����ˡ���Ϊ�����������
������Щ����·�Ե����˴�١�������ÿ�쵽�����ﶼҪ��Ҫ����һ��ʱ�䡣
���Ŷ���д��[�ϰ���]�������֣��Ծ���������
LONG
	);
	set("exits",([

		"north" : __DIR__"sroad6",
                "south" : "/d/emei/emroad5",
	]));
	set("objects",([
                 __DIR__"npc/wujiang2":1, 
                 __DIR__"npc/bing":2,
        ]));
set("outdoors", "changan");
	setup();
}
