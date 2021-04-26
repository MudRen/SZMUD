// Code of ShenZhou
// Room: /d/shaolin/zhulin5.c
// Date: YZC 96/01/19
// modified by aln 4 / 98
// modified by apache 12/98
// modified by xiaojian 06/2000, cut zuochan getting temp wuxing
inherit ROOM;

void create()
{
        set("short", "����С��");
        set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ������������
�ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��ľ������
΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ���
���������ڡ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"hsyuan5",
                "south" : __DIR__"zhulin4",
                "west" : __DIR__"cjlou",
                "north" : __DIR__"zhulin6",
        ]));


        set("outdoors", "shaolin");
        set("cost", 1);
        setup();
}

void init()
{
        add_action("do_zuochan", "zuochan");
}

int do_zuochan()
{
        object me = this_player();
        int level;

        if( (string)me->query("family/family_name") != "������" ) 
                return notify_fail("�㲻�����ֵ��ӣ������ڴ�������\n");

        if( (level = (int)me->query_skill("buddhism", 1)) < 120 )
                return notify_fail("��ķ���Ϊ̫�ͣ����������������С�\n");


        if (me->is_busy() || me->query_temp("pending/exercising")
            || me->query_temp("exit_blocked"))
                return notify_fail("��������æ���ء�\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("ս���о��ޣ�����������\n");

        if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
                return notify_fail("�����ھ��������޷�������ħ���ޡ�\n");

        if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
                return notify_fail("���������������������������ܾ��ޡ�\n");

        if( me->query_condition("zuochan") )
                return notify_fail("�����������\n");

        if( !(present("muyu chui", me)) )
                return notify_fail("�����ʹ��ľ��������������С�\n");

        message_vision("$N��ϥ���£������۾���ľ��������\n", me);

        me->start_busy(5);
        call_out("zuochaned", 5, me);
        return 1;
}

void zuochaned(object me)
{
        mapping skill_status, skill_learned, map, prepare, lrn;
        string *sname, *skills, skill, *mapskills, *preskills;  
        int amount, temp, i, m;
  
        string *slskills = ({
        "fengyun-shou",
        "qianye-shou",
        "banruo-zhang",
        "sanhua-zhang", 
        "jingang-quan",
        "luohan-quan",
        "cibei-dao",
        "xiuluo-dao",
        "wuchang-zhang",
        "pudu-zhang",
        "weituo-gun",
        "zui-gun",
        "nianhua-zhi",
        "yizhi-chan",
        "yingzhua-gong",
        "longzhua-gong",
        "fumo-jian",
        "damo-jian",

        "blade",
        "claw"
        "club",
        "cuff",
        "finger",
        "hand",
        "staff",
        "strike",
        "sword",
        });

        me->improve_skill("buddhism", random(200));

/* Added by apache to improve hyyq */
        lrn = me->query_learned();
        i = (int)lrn["hunyuan-yiqi"];
        m = (int)me->query_skill("hunyuan-yiqi", 1);
        if( (m >= 200) && (i > (m+1)*(m+1) ) )
            me->improve_skill("hunyuan-yiqi", 1);
/* End of modification. -Apache */

        amount = (int)me->query_skill("buddhism", 1) / 40;
        amount += random(amount);

        skill_status = me->query_skills();
        sname = keys(skill_status);
        skills = ({});
        for(i = 0; i < sizeof(sname); i++) {
                if( member_array(sname[i], slskills) != -1 )
                        skills += ({sname[i]});
        }

        if( !(sizeof(skills)) ) return;

        skill_learned = me->query_learned();
        temp = 0;
        map = me->query_skill_map();
        prepare = me->query_skill_prepare();
        for(i = 0; i < amount; i++) {
                skill = skills[random(sizeof(skills))];

                me->set("fgskills/" + skill, skill_status[skill]);
                me->set("fglearned/" + skill, skill_learned[skill]);
                me->delete_skill(skill);

                mapskills = keys(map);
                for(m = 0; m < sizeof(mapskills); m++) {
                        if( map[mapskills[m]] == skill )
                        map_delete(map, mapskills[m]);
                }

                preskills = keys(prepare);
                for(m = 0; m < sizeof(preskills); m++) {
                        if( prepare[preskills[m]] == skill )
                        map_delete(prepare, preskills[m]);
                }

                temp++;

                skills -= ({skill});
                if( sizeof(skills) < 1 ) break;
        }

        me->reset_action();

        message_vision("$N���������۾�������һ����վ��������\n", me);
        write("\n������˷��������ľ��磬��ʱ������ϰ���ʤ֮�ġ�\n");
        //me->add("int", temp);

        me->apply_condition("zuochan", amount );

        return;
}
