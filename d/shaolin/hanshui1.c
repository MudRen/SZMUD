// Code of ShenZhou
// Room: /d/shaolin/hanshui1.c
// Date: YZC 96/01/19
// modified by aln 4 / 98

inherit FERRY;

void create()
{
        object room;

        set("short", "��ˮ�ϰ�");
        set("long", @LONG
��ǰ��һ�����η����Ĵ�(river)���������������۾�����
�����ɴ���������������һ�����������̯����Ҿͽ������ڰ�
�ߣ���������֧һ��ľ�壬���ϰ����˻�������ĺ������㡣��
ȥ��Զ�����������Ϻӿڣ����ٹ����Ͷ�������ȴ��ɴ��ڶɡ�
LONG
    );

        set("exits", ([
                "south" : __DIR__"yidao2",
        ]));

        set("item_desc", ([
                "river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
        ]));

        set("objects",([
	        CLASS_D("gaibang") + "/jiang-shangyou" : 1,
        ]));

        set("resource/water", 1);
        set("outdoors", "shaolin");
	set("cost", 2);

        set("name", "��");
        set("boat", __DIR__"duchuan");
        set("opposite", __DIR__"hanshui2");
    
        setup();
}
