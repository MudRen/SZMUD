//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
�����Ž䱸ɭ�ϣ�һЩ�ٱ����ڼ��������ǵ����ˡ���ʱ�п�����������
�Ｑ����������Ŷ���д��[������]�������֣��Ծ���������
LONG
	);
	set("exits",([
		"east" : __DIR__"wroad4",
                "west" : "/d/xueshan/shanlu6",
	]));
	set("objects",([
                 __DIR__"npc/wujiang2":1,
                 __DIR__"npc/bing":2,
        ]));
set("outdoors", "changan");
	setup();
}
