//Creatived by Snso Zyu Tianhen
// /d/wuguan/xiulian.c
//������

inherit ROOM;

void create()
{
                  set("short", "������");
                  set("long", @LONG
������Ȫ����ݵĽ����ҡ����ڲ����ر���裬���Ϸ��ż������ţ�
����ǳ��������������Ǹ��������Եĺõط�,����֮�˶�������������
������ѧ���������š���������һ��С·����ͨ�����档
LONG
                  );
                  set("valid_startroom", 1);

                  set("exits", ([
                      "southwest" : __DIR__"zoulang3",
                  ]));

	set("objects", ([
//            __DIR__"npc/dizi3" : 1,
	    ]));

                set("cost",1);

                set("no_steal",1);

                setup();
}
