// Code of ShenZhou
//Kane
// Modified by xQin 04/01

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�Խ�ͤ");
        set("long", @LONG
����Сͤ����������ˮ�У�����ͤ���Ժ��ɴ�ɣ������ˮ�ӻأ����Ĺ���
�����֮��ͤ�ڹ���һ������ (duilian)�����Կ��д�ɣ������м���и�����
�ã�����һ��֮�⡣
LONG
        );

        set("item_desc", ([
        "duilian" : " \n
������������������������������
����    ��          ��    ����
����                      ����
����    ��          ��    ����
����                      ����
����    Ӱ          ��    ����
����                      ����
����    ��          ��    ����
����                      ����
����    ��          ��    ����
����                      ����
����    ��          ��    ����
����                      ����
����    ��          ��    ����
������������������������������
\n",
        ]));

        set("cost", 2);
        set("outdoors", "taohua");

        setup();
}

void init()
{
        add_action("do_jump", "fly");
          add_action("do_lian", "lian");
}

int do_jump(string arg)
{
        object me = this_player();

        if ( !arg || arg != "bank" )
             return notify_fail( "ʲô��\n");

        message_vision("$N������������ʯ��\n\n", me);
        me->move(__DIR__"tingyu");
        message("vision", me->name() + "�������Խ�ͤ�����˹�����\n",environment(me), ({me}) );

        return 1;
}

int do_lian(string arg)
{
        object me;
        string skillarg, skillname, skillzhao, multiple;
        int times, shijian, skill, skill_basic, qi;

        me = this_player();
        seteuid(getuid());

/*      if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

        if (where->query("sleep_room"))
                return notify_fail("��˯���ﲻ�����������Ӱ�����ˡ�\n");
*/
        if (me->query_temp("cursed", 1))
                return notify_fail("ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

        if( arg=="parry" )
                return notify_fail("�㲻��ͨ����ϰ�м����������ܡ�\n");

// FOLLOWING CODE ARE MODIFY BY SCATTER
//        if( !arg ) return (__DIR__"enable")->main(me, arg);
          if( !arg )
                   return notify_fail("�����㲻����ϰ\n");

        if(sscanf(arg, "%s %d", skillarg, times)!=2 )
                skillarg = arg;

        if( skillarg != "sword" ) return notify_fail("ʲô��\n");

        if( skillarg=="parry" )
                return notify_fail("�㲻��ͨ����ϰ�м����������ܡ�\n");

        if(!times || times == 0) {
                times = 1;
                multiple="";
        }
        else    multiple="����";
        shijian = times;

        if(!stringp(skillname = me->query_skill_mapped(skillarg)) )
                return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

        skill_basic = me->query_skill(skillarg, 1);
        skill = me->query_skill(skillname, 1);

        if( skill < 1 )
                return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
        if( skill_basic < 1 )
                return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
        if( skill_basic/2 <= skill/3 )
                return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        notify_fail("�����ڲ�����ϰ����ܡ�\n");
        if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

        notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");

        if(times < 0 ) return notify_fail("��Ҫ�����٣���\n");

        for(times; times > 0; times--) {
                if( SKILL_D(skillname)->practice_skill(me) )
                        me->improve_skill(skillname, skill_basic/3+1, skill_basic > skill? 0: 1);
                else return 0;
        }

        if(skillzhao = SKILL_D(skillname)->query_skill_name(me->query_skill(skillname, 1)))

        {
                message_vision( HIY"$N" + multiple + "��ϰ��" + to_chinese(skillname) + "�е�"
                                + skillzhao + "��һ�У�������Щ������\n"NOR, me);
                if( me->query_skill("bitao-xuangong", 1) > 80 )
                        me->add("shijian",shijian);
                me->add("jingli", -15);
        }


        else
        {
                message_vision( HIY"$N" + multiple + "��ϰ��" + to_chinese(skillname) + "��������Щ������\n"NOR, me);
                if( me->query_skill("bitao-xuangong", 1) > 80 )
                        me->add("shijian", shijian);
                me->add("jingli", -15);
        }

        return 1;
}
