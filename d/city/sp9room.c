// Code of ShenZhou
// by ding@xkx
// modified by aln@xkx

inherit "/inherit/room/p9room";

void create()
{
        set("short", "�ƾ���");
        set("long", @LONG
���������ƾŵĵط��������м����һ�Ŵ�̨�ӡ�̨���Ա����Ÿ�
С���� (paizi)������ĵ���С�ƾţ�ÿ�������ƣ�һ��һ���ۡ��ĳ�
��ׯ�ң��Ŀ�ֻ��ѹ��bet���мҡ�
LONG );

        set("exits", ([
                "southeast" : "/d/city/duchang",
        ]));

        set("item_desc", ([
                "paizi" : 
"�ĳ���˰���壬���ĳ�������ɢ������\n"
"�ƾŵ��淨���ܿ��Կ� help paigow.\n",
        ]));

        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");

        set("cost", 0);
        setup();

}
