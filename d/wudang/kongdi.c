// Code of ShenZhou
//maco

inherit ROOM;

void create()
{
        set("short", "�յ�");
        set("long", @LONG
���ǻ�ɽ�еĿյأ�ǰ����һ��é�ᣬ��ǰ��ɢ��������������(hillock) 
����������ï�ܣ�ż����ȸ��������Ϊ�ľ�����é�����ݶ����ṹ��Ȼƽƽ��
�棬�����������أ�������ɽ�о�����Ϊһ�壬�������⾳��������˼֮����
����Ȼ��¶��
LONG
        );
         set("exits", ([
                "south" : __DIR__"wdroad5",
                "enter" : __DIR__"maoshe",
        ]));

         set("objects", ([
                 "/d/taohua/obj/shizi" : 1,
        ]));
        set("item_desc", ([
        "hillock" : "é���������һ�ѣ���һ�ѣ��������߰��㣬�м�ȴ�ƺ������������ȵı仯��\n",
        ]));

        set("outdoors", "wudang");
        set("cost", 1);

        setup();
}
int valid_leave(object me, string dir)
{

        if(dir == "enter") { 
        if( present("tie bagua", me)  ) {
        message_vision("$N�����������ϵ�����λ�߹������ѡ�\n", me);
        return ::valid_leave(me, dir);
        }

        else if( me->query("family/family_name") != "�һ���" && me->query_skill("qimen-dunjia", 1) < 90  ) {
        message_vision("$N������ǰ������ȥ������Ҫ�죬ʼ���߲���ȥ��\n", me);
                return notify_fail("");
        }

        else {
        }
        message_vision("$Nת�˼�ת���������׵ı��ƹ����ѣ���Ȼ��Ȼ���Ų����ݡ�\n", me);
        return ::valid_leave(me, dir);
        }
        else return ::valid_leave(me, dir);
}
