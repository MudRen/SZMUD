// Code of ShenZhou
// Mantian remove Ssy north room path since mirror and @us ppl can't access wiz tree 05/12/2001
// Mantian add up path to �齫 room 05/12/2001


inherit ROOM;

void create()
{
        set("short", "С��ի");
        set("long", @LONG
��һ�߽�����㱻���︻���ûʵ�װ������һ������ԭ���������¹
����Τ��ү�¿���С��ի��ר���޸�����������ߣ���ΪΤ��ү����������
�ʴ󣬶��Ҵ��»�������ط��ǽύ�������ѵģ���������ʲ�����װ����
�ܺܿ��޺ã������շѲ��ߡ�¥�����½����ŵġ�Τ�Ϲ�˾����
LONG
        );
//        set("outdoors", "city");

        set("exits", ([
                "south" : __DIR__"dongnanjie",
//				"north" : "/u/ssy/paimai",
//				"west" : __DIR__"nandajie2",
				"up" : __DIR__"mjroom",
        ]));

        set("objects", ([
                // __DIR__"npc/shuanger" : 1,
                // __DIR__"npc/xiaoping" : 1,
                // "/kungfu/class/shenlong/su" : 1,
        ]));

        set("cost", 0);
        setup();
}
