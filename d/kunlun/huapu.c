//huapu.c (kunlun) 
inherit ROOM;
int do_pull(string arg);
void create()
{
        set("short", "����");
        set("long", @LONG
������һ���������ľ��Ļ�԰��԰�����������������ҹŹֵ��ʻ�����ѩ
�컨����Ҷ������һ�������ҹ��ȵ�ͼ����
LONG
        );
        set("outdoors", "huapu");
        set("exits", ([
           "north" : __DIR__"tieqinju",
        ]));
        set("item_desc", ([
    "�ʻ�" : "    �⻨����ʱ��̴��֮�����������ɫ�ּ����ޡ��侥������ɫ��졣��
���Ǵ�����������֬����\n",
    "flower" : "    �⻨����ʱ��̴��֮�����������ɫ�ּ����ޡ��侥������ɫ��졣��
���Ǵ�����������֬����\n",
        ]));
        setup();
        set("flower",1);
}
void init()
{
        add_action("do_pull", "pull");
}
int do_pull(string arg)
{
        object me,ob;
        me = this_player();
        if (!arg )
                return notify_fail("��Ҫ��ʲô��\n");
          if ( arg != "��֬��" && arg != "flower" )
                return notify_fail("��Ҫ��ʲô��\n");
        if( (int)query("flower") ){
                ob=new(__DIR__"obj/lingzhiflower");
                  message_vision("$N�γ�һ"+ob->query("unit")+ob->query("name")+"��\n",me);
                if (!ob->move(me))
                        ob->move(environment(me));
                delete("flower");
                delete("item_desc");
                return 1;
        }
          return notify_fail("�������֬�����ι��ˡ�\n");
}
