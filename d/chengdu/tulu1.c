//  /d/xueshan/shanlu.c 
inherit ROOM;
 void create()
{
       set("short", "��·");
       set("long", @LONG
����һ�����������С·����Ϊ�Ĵ��Թž��Ǹ���֮�أ����Է�����ȥ��
���ܵ��������������ࡣԶ��������ɽ����Ŀ��ȥ�����������棬Ī�Ǿ�����
���Ķ���ɽ�����������Ϳ쵽���ص�����ˡ�
LONG);
        set("outdoors", "emei");
        set("cost", 1);
       set("exits", ([
               "northeast" : __DIR__"sroad1",
                          "south" : "/d/emei/shijie2",
                          "northwest" : __DIR__"shanlu01",
       ]));

       setup(); 
       replace_program(ROOM);
}


