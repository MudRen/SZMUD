// Code of ShenZhou
///d/zhongnan/npc/killer.c ɱ��
// sdong 08/15/98

inherit NPC;

void create()
{
    set_name("ɱ��", ({ "killer","killer" }) );
    set("age", 40);
    set("gender", "����");
    set("combat_exp", 5000);
    set("shen_type", -1);
    set("attitude", "heroism");
    setup();
    add_money("silver", random(50));
}

void init()
{
    object *inv, *ob,me = this_object();
    mapping skill_status;
    string *sname;
    int i, max = 0, max1, j=0,sum_exp=0;


    if ( !me->query_temp("copied") ) {

    inv = all_inventory(environment());
    ob = all_inventory(environment());

    j=0;
    for(i=0;i<sizeof(inv);i++)
    {
     if( inv[i]->query_temp("pending/beidou",1) )
         {
            ob[j] = inv[i]; j++;
         }
    }

    if( j==0) return;

    if(j>0)
    {
        sum_exp = 0;
        for(i=0;i<j;i++)
        {
            sum_exp += (ob[i])->query("combat_exp",1);
        }
    }

        j -= 1;
      if (j==0)j=1;
        max = sum_exp / j ;


        max = pow(max*10.,0.33333);

        max1 = (int)max + 1;
        max = (int)max + 1 + random((int)max/4);

        me->set_skill("dodge", max1);
        me->set_skill("parry", max1 );
        me->set_skill("force", max1);

        switch( random(6) )
        {
            case 0:
                me->set_skill("cuff", max1);
                me->set_skill("yujiamu-quan", max1);
                me->map_skill("cuff", "yujiamu-quan");
                me->prepare_skill("cuff", "yujiamu-quan");
                me->set_skill("hand", max1);
                me->set_skill("dashou-yin", max1);
                me->map_skill("hand", "dashou-yin");
                me->prepare_skill("hand", "dashouyin");
                me->set_skill("longxiang-banruo", max1);
                me->map_skill("force", "longxiang-banruo");
                me->set_skill("shenkongxing", max1);
                me->map_skill("dodge", "shenkongxing");
                switch( random(2) ) {
                case 0:
                        set_name("�����", ({ "darba","da" }) );
                        set("long",
"���ǽ��ַ����Ķ����ӣ��ѵ÷����塢�����洫��������������һ�����Ź��� \n"
"�����˵ã������θ��ݣ�ȴʹһ�������ĳߵĴ���ħ�ơ�\n");
                        set("age", 40);
                        me->set_skill("staff", max);
                        me->set_skill("jingang-chu", max);
                        me->map_skill("staff", "jingang-chu");
                        me->map_skill("parry", "jingang-chu");
                        setup();
                        me->carry_object("/clone/weapon/tiezhang")->wield();
                        break;
                case 1:
                            if(random(10)==0)
                            {
                              set_name("���ַ���", ({ "jinlun fawang","fawang" }) );
                              set("long",
"һ�����귬ɮ�����μ��߼��ݣ�����һ������ˡ�����΢�ݣ�����һ�����ӡ�\n"
"�����ǵ����ɹŹ�����������\n");
                              set("title", "�ɹŹ�ʦ");
                              set("gender", "����");
                              set("age", 50);
                              set("class","lama");
                              set("shen_type", -1);

                                me->set_skill("hammer", max*5/4);
                                me->set_skill("riyue-lun", max*5/4);
                                me->map_skill("hammer", "riyue-lun");
                                me->map_skill("parry", "riyue-lun");
                                setup();
                                me->carry_object("/clone/weapon/falun")->set_amount(4);
                                me->carry_object("/clone/weapon/falun")->wield();
                                command("wield falun");
                            }
                            else
                            {
                                set_name("����", ({ "huo du","huo" }) );
                                set("long",
"���ǽ��ַ����������ӣ������û�������̬����������˫Ŀб�ɡ�\n");
                                set("title", "�ɹ�����");
                                me->set_skill("sword", max);
                                me->set_skill("mingwang-jian", max);
                                me->map_skill("sword", "mingwang-jian");
                                me->map_skill("parry", "mingwang-jian");
                                setup();
                                me->carry_object("/clone/weapon/changjian")->wield();
                             }
                            break;
            }
            break;
        case 1:
              set_name("ɳͨ��", ({ "sha tongtian", "sha" }));
              set("nickname", "��������");
              set("long",
"ɳͨ���Ǹ�ͺ�ӣ�ͷ���͹���û���ͷ����˫Ŀ������˿����\n"
"��ͻ��������һ�����ࡣ���ӱ��꣬�书ȴ�ǳ���ظߣ�������\n"
"���˲�����\n");
              set("title", "�ƺӰ����");
              set("gender", "����");
              set("age", 48);
              set("attitude", "peaceful");
              set("shen_type", -1);
              me->set_skill("force", max1);
              me->set_skill("dodge", max1);
              me->set_skill("parry", max1);
              me->set_skill("cuff", max1);
              set_skill("wuxingbu", max);
              set_skill("wuxing-quan", max);
              set_skill("wuhu-gun", max);
              set_skill("staff", max1);
              set_skill("ding-force", max1);

              map_skill("dodge", "wuxingbu");
              map_skill("staff", "wuhu-gun");
              map_skill("parry", "wuhu-gun");
              map_skill("cuff", "wuxing-quan");
              map_skill("force", "ding-force");

              prepare_skill("cuff", "wuxing-quan");

              setup();
              carry_object("/clone/weapon/tiejiang")->wield();
              carry_object("/d/city/obj/tiejia")->wear();
            break;
        case 2:
              set_name("������", ({ "liang ziweng", "liang" }));
              set("nickname", "�����Ϲ�");
              set("long",
"����������еȣ���ͷ�׷�����������ɫ����������ģ���һ\n"
"���𲼳��ۣ����ǵ����ס����ǳ���ɽ��ѧ��һ����ʦ��\n");
              set("gender", "����");
              set("age", 45);
              set("shen_type", -1);

              set_skill("force", max1);
              set_skill("ding-force", max1);
              set_skill("wuxingbu", max1);
              set_skill("yanqing-quan", max);
              set_skill("cuff", max);
              set_skill("hammer", max1);
              set_skill("taoism",50);

              map_skill("force", "ding-force");
              map_skill("dodge", "wuxingbu");
              map_skill("cuff", "yanqing-quan");
              map_skill("parry", "yanqing-quan");

              prepare_skill("cuff", "yanqing-quan");

              setup();
              carry_object("/clone/weapon/yaochu2");
              carry_object("/clone/anqi/tougu-ding")->set_amount(7);
              carry_object("/clone/armor/gebu-changpao")->wear();

            break;
        case 3:

            set_name("ŷ����", ({ "ouyang ke", "ouyang", "ke" }));
            set("long", "��һ����£����û�������̬����������˫Ŀб�ɣ���Ŀ���ţ�ȴ\n��Ӣ�����ˡ�"
                 "���Ϸ��δ�磬ٲȻ��һλ�������\n");
            set("title", "����ɽ��ׯ��");
            set("gender", "����");
            set("shen_type", -1);
            set("age", 35);
            me->set_skill("strike", max1);
            me->set_skill("hamagong", max1);
            me->set_skill("hand", max1);
            me->set_skill("shexing-diaoshou", max1);
            me->map_skill("hand", "shexing-diaoshou");
            if ( max > 100 ) {
                me->map_skill("strike", "hamagong");
                me->prepare_skill("strike", "hamagong");
            }
            else {
                me->prepare_skill("hand", "shexing-diaoshou");
            }
            me->map_skill("force", "hamagong");
            me->set_skill("staff", max);
            me->set_skill("lingshe-zhang", max);
            me->map_skill("staff", "lingshe-zhang");
            me->map_skill("parry", "lingshe-zhang");
            me->set_skill("chanchubu", max1);
            me->map_skill("dodge", "chanchubu");
            setup();
            me->carry_object("/clone/weapon/tiezhang")->wield();
            break;
         case 4:
          set_name("������", ({ "peng lianhu", "peng" }));
          set("nickname", "ǧ������");
          set("long",
"�����������ģ����ۺ�˿��Ŀ����磬�ϴ��������������Բб�����ɳͨ�������Ľ��顣\n");
          set("gender", "����");
          set("age", 49);
          set("shen_type", -1);
          set_skill("force", max1);
          set_skill("dodge", max1);
          set_skill("wuxingbu", max1);
          set_skill("parry", max1);
          set_skill("cuff", max);
          set_skill("wuxing-quan", max);
          set_skill("club", max1);
          set_skill("ding-force", max1);
          set_skill("liuhe-qiang", max);

          map_skill("club", "liuhe-qiang");
          map_skill("parry", "liuhe-qiang");
          map_skill("dodge", "wuxingbu");
          map_skill("cuff", "wuxing-quan");
          map_skill("force", "ding-force");

          prepare_skill("cuff", "wuxing-quan");

          setup();
          carry_object("/clone/weapon/panguanbi")->wield();
          carry_object("/d/shaolin/obj/beixin")->wear();
          carry_object("/clone/weapon/jqbiao")->set_amount(7);

          break;

         case 5:
              set_name("������", ({ "yin kexi","yin","kexi" }));
              set("long", "�������Ǹ���˹���ˣ��߱���Ŀ����ǰ�Ǹ��鱦�̣���Ϊ��ͨ���ʣ���ŷ�������������˷�������\n");
              set("gender", "����");
              set("title","����ɽׯ�˷�����");
              set("age", 35);
              set_skill("hand", max);
              set_skill("shexing-diaoshou", max);
              set_skill("dodge", max1);
              set_skill("chanchubu", max1);
              set_skill("parry", max1);
              set_skill("force", max1);
              set_skill("hamagong", max1);
              set_skill("strike",max1);
              set_skill("poison",max1);
              set_skill("training",max1);
              map_skill("hand","shexing-diaoshou");
              map_skill("dodge","chanchubu");
              map_skill("force","hamagong");
              setup();
              prepare_skill("hand","shexing-diaoshou");
          break;
        }

        sum_exp = sum_exp/j;
        me->set("combat_exp", sum_exp+random(sum_exp/2));
        me->set("max_qi", ob[0]->query("max_qi"));
        me->set("eff_qi", ob[0]->query("max_qi"));
        me->set("max_jing", ob[0]->query("max_jing"));
        me->set("eff_jing", ob[0]->query("max_jing"));
        me->set("qi", me->query("max_qi"));
        me->set("jing", me->query("max_jing"));
        me->set("jiali", 50);
        if ( ob[0]->query("max_neili") > 0 ) {
            me->set("max_neili", ob[0]->query("max_neili"));
        }
        else me->set("max_neili", 500);
        if ( ob[0]->query("max_jingli") > 0 ) {
            me->set("max_jingli", ob[0]->query("max_jingli"));
        }
        else me->set("max_jingli", 500);
        me->set("neili", me->query("max_neili"));
        me->set("jingli", me->query("max_jingli"));

        me->set("no_sing", 1);
        me->set_temp("copied", 1);
    }

    me->set("shen", (int)(-me->query("combat_exp")/10) );


    if ( !me->query_temp("said") ) {
          switch( random(4) )
          {
        case 0:
            command( "grin" );
            command( "say ��ƾ����ţ���ӵ�����è����Ҳ��������Ȼ�������������ѵ��ѵ�㣬���У�" );
            break;
        case 1:
            command( "hehe" );
            command( "say ��˵�����澭���������������ǧ�������صظ��������Ǿ������ɣ�" );
            break;
        case 2:
            command( "hehe" );
            command( "say ȫ�����ô�����ͷ�����ӿ���Ҳ������ˡ���ţ���ӣ���������ɣ�" );
            break;
        default:
            command( "hehe" );
            command( "say �����ҿ�����ţ���Ӳ�˳�ۣ��ص�����������������������������ɣ�" );
            break;
          }
          me->set_temp("said", 1);
    }

    for(i=0;i<j;i++)
    {
        ob[i]->kill_ob(me);
        kill_ob(ob[i]);
    }
}

int destruct_me(object me)
{
    if(me) {
        message_vision("$N�Ҵ�ææ���뿪�ˡ�\n\n", me);
        destruct(me);
    }
    return 1;
}


int accept_fight(object victim)
{
    object me = this_object();

    command( "say ��������ı��ӵ��������ҷ�����" );
    me->set_temp("fought", 1);
    me->kill_ob(victim);

//    remove_call_out("checking");
//    call_out("checking", 1, me, victim,me->query_temp("bonus",1)+random(2));
    return 1;
}

int accept_kill(object victim)
{
    object me = this_object();

    command( "say ��֪����Ķ������ô�ү�ҳ�����ɣ�" );
    me->kill_ob(victim);

//    remove_call_out("checking");
//    call_out("checking", 1, me, victim,me->query_temp("bonus",1)+random(2));
    remove_call_out( "destruct_me" );
    call_out( "destruct_me", 1, me ); 
    return 1;
}

/*
void unconcious()
{
    object me=this_object();
    object ob = me->query_temp("last_damage_from");

    if( random(20) == 10)
    {
        message_vision("\n$N�޺޵�˵����û�뵽ţ������צ����ôӲ���´������鷳��\n", this_object());
        message_vision("$N�������һ�����Ҵ�ææ�뿪�ˡ�\n", this_object());
        destruct(me);
        tell_object(ob,"\n���Ǳ�ܺ��������ˣ�\n");
        ob->add("potential",me->query_temp("bonus",1) );
        if(ob->query("potential",1)>ob->query("max_potential",1) )
            ob->set("potential",ob->query("max_potential",1));
    }
    ::unconcious();

}

void die()
{
    int pot,exp;
    object me=this_object();
    object ob = me->query_temp("last_damage_from");

     if( !living(me) ) {revive(1);reincarnate();}

    if( me->query("combat_exp") > ob->query("combat_exp")/2 && random(2) == 0)
    {
        exp = 6*me->query_temp("bonus",1)+6*random(me->query_temp("bonus",1));
        if(exp<50)exp=50;
        if(exp>140)exp=140;
        pot = 3*me->query_temp("bonus",1)+3*random(me->query_temp("bonus",1));
        if(pot<25)pot=25;
        if(pot>65)pot=65;
        ob->add("combat_exp", exp);
        ob->add("potential", pot);
        if ( ob->query("potential") > ob->query("max_potential") )
            ob->set("potential", ob->query("max_potential"));
        tell_object(ob,"\n��ľ����Ǳ�ܺ�������ˣ�\n");
        ::die();
    }
    else
    {
        message_vision("\nǽ�Ϻ�Ȼ��������������$Nһ�ѱ��𣬺ȵ���ͺ���������ҵ��ֵܡ�\n", this_object());
        message_vision("�����˴���$N��ǽ��һ�����Ҵ�ææ�뿪�ˡ�\n", this_object());
        tell_object(ob,"\n���Ǳ�ܺ��������ˣ�\n");
        ob->add("potential",me->query_temp("bonus",1)*2 );
        if(ob->query("potential",1)>ob->query("max_potential",1) )
            ob->set("potential",ob->query("max_potential",1));
        destruct(me);
    }
}
*/
