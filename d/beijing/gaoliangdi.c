//Cracked by Roath
// /d/changbai/gaoliangdi.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǳ��������ĸ����أ�������ʮĶ������ϡϡ���䡣�����������
��ũ�ᣬ������ʣ��ƿ����ţ��㷢�ֽ�����˲���ũ�ߡ�������һ��СԺ�ӡ�
LONG
        );

        set("outdoors", "shenlong");

        set("exits", ([
                "south" : __DIR__"yidao2",
        ]));

        set("objects",([
            //    "/kungfu/class/shenlong/hong" : 1,
                "/kungfu/class/shenlong/xu" : 1,
                
        ]));

        set("cost", 3);

        setup();
        replace_program(ROOM);
}
