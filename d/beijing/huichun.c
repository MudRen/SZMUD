//Cracked by Roath
// Room:�ش��� 
// Ssy 

inherit ROOM;

void create()
{
        set("short", "�ش���");
        set("long", @LONG
���Ǿ������ֺ�ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ���
��С������ɢ�������ġ�һλ������ڰ������ԣ���˵�����Ǿ����������Ĵ��
Ҧ����������ҽ�������ˡ�һ��С���վ�ڹ�̨���к��Ź˿͡���̨������һ��
���(guanggao)��
LONG
        );
        set("item_desc", ([
			   "guanggao" : "�������ҩƷ���������˲��ˡ�\n",
        ]));

        set("objects", ([
			 __DIR__"npc/yaochun" : 1,
			 __DIR__"npc/hcthuoji" : 1,
        ]));

        set("exits", ([
		       "east" : __DIR__"fuchengdajie_s",
        ]));

        set("cost", 0);
        set("day_shop", 1);
        setup();
        replace_program(ROOM);
}
