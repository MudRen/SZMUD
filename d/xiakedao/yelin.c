//Cracked by Roath
// yelin Ұ��
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "Ұ��");
    	set("long", @LONG
һƬ��ɭɭ��Ұ�֣���֪ͨ��η���żȻ�м�ֻ��ѻ�ɹ�������
�ؽм������㲻�ɵ�ֻ�뾡���߳���ƬҰ�֡�
LONG
    	);

    	set("exits", ([
		       "northup": __DIR__"shanding",
		       "east" : __DIR__"yelin",
		       "west" : __DIR__"yelin",
		       "south" : __DIR__"haidaowo",
		       ]));
    	set("outdoors", "xiakedao");
        set("objects", ([ 
                         __DIR__ + "npc/wuya" : 2,
                         ]));

    	setup();
}


