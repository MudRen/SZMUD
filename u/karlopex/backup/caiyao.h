// Code of ShenZhou
// /d/zhongnan/caiyao.h
// caiyao.h  ��ҩ
// sdong 08/06/98

#include <ansi.h>

void setup_ob(object me,object victiom);
string *herbs = ({
                     HERB_D("chuanbei"),
                     HERB_D("fuling"),
                     HERB_D("gouzhizi"),
                     HERB_D("heshouwu"),
                     HERB_D("huanglian"),
                     HERB_D("jugeng"),
                     HERB_D("jy-hua"),
                     HERB_D("shengdi"),
});

string *beasts = ({
                     BEAST_D("snake"),
                     BEAST_D("bee"),
                     BEAST_D("wuya"),
                     BEAST_D("yetu"),
                     BEAST_D("deer"),
                     BEAST_D("xbaozi"),
                     BEAST_D("monkey"),
});


void init()
{
    object ob = this_player();
    add_action("do_search", "bo");
    add_action("do_search", "search");
    add_action("do_dig", "wa");
    add_action("do_dig", "dig");
    if( interactive(ob))
    {
        this_player()->delete_temp("herb");
        if( ob->query_temp("qz/caiyao") )
            set("count",random(4));
    }
}

int do_search(string arg)
{
          object me,ob;
          int power;


          me = this_player();

          if( me->is_fighting() || me->is_busy() )
                     return notify_fail("����æ�š�\n");

          if( me->query_temp("herb/got",1) )
                     return notify_fail("�����Ѿ��ҹ��ˣ�����Ҳ�Ҳ���ʲô�ˣ�\n");

          if( !present("yao chu", me) )
                     return notify_fail("��û�й��ߣ��޷�������ľɽ��Ѱ�Ҳ�ҩ��\n");

          if( (int)me->query("jingli") < 30 )
                     return notify_fail("��̫���ˣ���ЪϢһ����ɡ�\n");

          me->add_temp("herb/times", 1);
          me->add("jingli", -2);
          me->start_busy(1+random(2));

          if( query("count") < 1 && (int)me->query_temp("herb/times") > 30 )
                     return notify_fail("������ܵĹ�ľ�Ӳݶ������ˣ�����û����ʲô����������ûָ���ˣ�\n");

          message_vision("$N��ҩ�����������ܵĹ�ľ�Ӳݣ���ϸ�ؿ���û�в�ҩ��\n", me);

          power = (int)me->query_temp("herb/times") * ( me->query("kar")+me->query("int") + me->query("str") )/3;
          power *= query("count");

          if( power/2 + random(power/2) > 150 ) {
                     me->set_temp("herb/found", 1);
                     message_vision(HIG"\n$N��ҩ�����ϵĲ��������ܵ�ɽ�ݣ���Ȼ�����Ӳ�֮����һ���ر�Ĳݣ�\n"NOR, me);
                    return 1;
          }

          if(random(10)==1 && (int)me->query("combat_exp") > 10000 )
          {
                ob=new(beasts[random(sizeof(beasts))]);
                ob->move(environment(me));
                message_vision(HIR"ͻȻ�Ӳݴ��о���һֻ$N����������˾��ţ������Ƶ���$n���������\n"NOR, ob,me);

                if(ob->query("id")=="xiao baozi")setup_ob(ob,me);
                ob->kill_ob(me);
                ob->start_busy(1+random(3));
                return 1;
          }

          /*if(random(101)==50 && (int)me->query("combat_exp") > 10000)
          {
             message_vision(HIR"\n$Nһ��С���������ͣ������°�һ����ҩ����Ϊ���أ�\n"NOR, me);
             ob = present("yao chu", me);
             if(ob)destruct(ob);
          }*/
          return 1;
}

void setup_ob(object me,object victim)
{
    object *inv;
    mapping skill_status;
    string *sname;
    int i, max = 0, max1, j;


    if ( !me->query_temp("copied") ) {
        if ( mapp(skill_status = victim->query_skills()) ) {
        skill_status = victim->query_skills();
        sname = keys(skill_status);

        for(i=0; i<sizeof(skill_status); i++) {
            if ( skill_status[sname[i]] > max ) max = skill_status[sname[i]];
        }


        max1 = (int)max + random(max);

        //max = (int)max*3/4 + 1 + random((int)max/4);

        if( victim->query("combat_exp",1) < 10000 ) max1/2;
        me->set_skill("dodge", max1);
        me->set_skill("parry", max1 );
        me->set_skill("force", max1);

        me->set("combat_exp", victim->query("combat_exp",1)+random(victim->query("combat_exp",1)/10));

        me->set("max_qi", victim->query("max_qi"));
        me->set("eff_qi", victim->query("max_qi"));
        me->set("max_jing", victim->query("max_jing"));
        me->set("eff_jing", victim->query("max_jing"));
        me->set("qi", me->query("max_qi"));
        me->set("jing", me->query("max_jing"));
        me->set("jiali", victim->query("jiali")*3/4);
        if ( victim->query("max_jingli") > 0 ) {
            me->set("max_jingli", victim->query("max_jingli"));
        }
        else me->set("max_jingli", 500);
        me->set("jingli", me->query("max_jingli"));

        me->set("no_sing", 1);
        me->set_temp("copied", 1);
        }
    }
}

int do_dig(string arg)
{
    object me, ob,herb;
    int exp;

    me = this_player();

    if( me->is_fighting() || me->is_busy() )
        return notify_fail("����æ�š�\n");
    if( !(ob = present("yao chu", me)) )
        return notify_fail("��û��ҩ������ô�ڣ�\n");

    if( (int)me->query("jingli") < 25 )
        return notify_fail("��̫���ˣ���ЪϢһ����ɡ�\n");

    me->add("jingli", -20);
    me->start_busy(1);

    if( !me->query_temp("herb/found") ) {
        message_vision("$N����ҩ��ʹ�����������������°�һ����ҩ����Ϊ���أ�\n", me);
        destruct(ob);
        return 1;
    }

    add("count", -1);
    herb = new(herbs[random(sizeof(herbs))]);
    herb->move(me);
    herb->set("player", me->query("id"));

    message_vision(HIY"$N��ҩ��С�������İ�$n"+HIY"�����������\n"NOR, me,herb);
    if(me->query_temp("qz/caiyao",1))
    {
        exp = 180 + random( 40 );
        me->add("combat_exp",exp);
        me->add("potential",exp*2/5);
 	    me->add_temp("qz/jobexp",exp);
 	    me->add_temp("qz/jobpot",exp/3);
        if(me->query("potential")>me->query("max_potential"))
            me->set("potential",me->query("max_potential"));
    }

    message_vision(HIR"\n$N�˷ܹ��ȣ���ҩ��һ˦�������°�һ����ҩ����Ϊ���أ�\n"NOR, me);
    destruct(ob);
    me->delete_temp("herb/found");
    me->set_temp("herb/got", 1);
    return 1;
}
