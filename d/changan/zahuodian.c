//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�ӻ���");
	set("long",@LONG
����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ���ƹ�
�����������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ���صĶ�
����̯������һ������(zhaopai)��
LONG
	);
        set("item_desc", ([
                "zhaopai": "���� \"list\" �г������\"buy\" ��С�����\n",
       ]));
	set("exits",([

                "west" : __DIR__"sroad3",
	]));
          set("objects", ([
             __DIR__"npc/xiao-fan": 1,
          ]));

          set("cost", 0);

	setup();
}
