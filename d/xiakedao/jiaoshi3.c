//Cracked by Roath
// Dong 1/9/98
// modifiedy by aln 5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "��ʯ");
    	set("long", @LONG
������һ�߷��Ͳ���ˣ�����������᾵Ľ�ʯ����ɭɭ�ģ���
�䵽��ҹ�䣬����������ʬ��ɢ���ӫ�����������ȷ��⣬�㻹
�ǿ���뿪����ɡ�
LONG
    	);

    	set("exits", ([
		       "north" : __DIR__"jiaoshi2",
		       "southwest" : __DIR__"shatans3",
		       ]));
    	set("outdoors", "xiakedao");
        set("objects", ([ 
                         "/d/city/obj/stone" : 1,
        ]));


    	setup();
}


