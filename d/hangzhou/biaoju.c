// Code of ShenZhou
// /d/hangzhou/biaoju.c  �����ھ�
// by aln  2 / 98

inherit ROOM;

void create()
{
        set("short", "�����ھ�");
        set("long", @LONG
�������㽭һ��������������ھ֡������ھ֡�������ͷ�˽������˳�
������ܡ��Ķ�����������ھ����������ʮ����������û���������ӡ�
�ſ�ʯ̳�ϲ���һ�����ɶ�ߵ���ˣ�����Ʈ��һ������һβ��ɫ�������
�졣
LONG
        );
/*
        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));
*/

        set("exits", ([
                "west" : __DIR__"road20",
                "enter" : __DIR__"xiaoyuan",
        ]));

        set("objects", ([
                __DIR__"npc/du" : 1,
        ]));

        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        object ob;

        if( dir != "enter" )
                return ::valid_leave(me, dir);

        if( !(ob = present("du dajin", environment(me))) )
                return ::valid_leave(me, dir);

        if( !living(ob) )
                return ::valid_leave(me, dir);

        if( me == ob )
                return ::valid_leave(me, dir);

        if( !me->query_condition("lmjob") ) {
                message_vision("$N����$n��ǰ���ȵ���" + RANK_D->query_rude(me) + "�������ھ��صأ����ô��룡\n", ob, me);
                return notify_fail("");
        }

        return ::valid_leave(me, dir);
}

/*
string look_gaoshi()
{
        object place;
        string str, *skills, *teachs;
        int i;

        if( !(place = find_object("/d/hangzhou/xiaoyuan")) )
                place = load_object("/d/hangzhou/xiaoyuan");
  
        if( time() > (int)place->query("time") + 3600 ) {
                place->set("time", time());

                skills = ({});
                for(i = 0; i < sizeof(lmskills); i++) {
                        teachs = lmskills[i];
                        skills += ({teachs[random(sizeof(teachs))]});
                }
                place->set("skills", skills);
        }

        skills = place->query("skills");
        str = "\nٷ����ʦ���������书��\n\n";
        for(i = 0; i < sizeof(skills); i++)
                str += to_chinese(skills[i]) + "��\n";
        str += "\n\n�����ھ�\n";
        return str;
}
*/
