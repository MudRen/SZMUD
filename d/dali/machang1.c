// Code of ShenZhou
inherit ROOM;

int do_exercise(string);

void create()
{
        set("short", "��");
        set("long", @LONG
�����ǰ��һ��Ƭ�����͵Ĳ�ƺ��̧����ȥ�����Կ���������Զ
���������Ӱ������ɢɢ����ļ�ƥҰ��(horse)���ڳԲݡ�
LONG
        );
        set("outdoors", "dali");

        set("item_desc", ([
                "horse" :
"����׼������������ģ�һ�������������󣬿�����һ��Ұ����ѱ�����ӡ�\n"

])  ) ;

        set("objects", ([
                "/d/dali/npc/mafu" : 1,
]));
        set("cost", 3);
        setup();
}

void init()
{
        add_action("do_exercise", "exercise");
}

int do_exercise(string arg)

{
        object me = this_player();

if ( me->query("job/description") == "����ƽ���������" )
 
        {
                tell_object(me, "�㻹��ר������ɣ�\n");
                return 1;
        }
        
        return 0;
}


int valid_leave(object me, string dir)
{
        mapping myfam;

        myfam = (mapping)me->query("family");

        if ( (string)me->query("job/description") == "����ƽ���������" )
        if (objectp(present("ma fu", environment(me))))
return notify_fail("���ȵ������������죬������\n");        
else            
        {
                message_vision("$N������ڣ��û������ˡ�\n", 
me);         

                me->delete_temp("apply/short");
                me->add("job/fail", 1);
                me->delete("job/supervisor");
                me->delete("job/description");
                me->delete("job/object");
        }
        

        
        return ::valid_leave(me, dir);
}


