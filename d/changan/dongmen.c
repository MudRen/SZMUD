//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
�����Ž䱸ɭ�ϣ�һЩ�ٱ����ڼ��������ǵ����ˡ���ʱ�п�������
�����Ｑ������������͵�֪�����ŵĹ��ġ�������ÿ�쵽�����ﶼҪ��Ҫ��
��һ��ʱ�䡣���Ŷ���д��[������]�������֣��Ծ���������
LONG
	);
	set("exits",([

		"west" : __DIR__"eroad3",
                "east" : "/d/village/sroad1",
		
	]));
	set("objects",([
                 __DIR__"npc/wujiang2":1,
                 __DIR__"npc/bing":2,
        ]));


         set("outdoors", "changan");
	setup();
}
