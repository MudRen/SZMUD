// Code of ShenZhou
// /kungfu/class/emei/pers_job.h
// yasuko: 2000/09/13
#include <ansi.h>

#define BUSY_TIME       180
void setupras( object rascal, object me );
/*
int  per_end(object me,object target);
*/
string *place = ({
        "/d/emei/",
});

string *area = ({
        "����",
});

string *ras_name = ({
        "��å",
        "����",
        "��Ʀ",
        "���ְ���",
        "С���",
        "��ͽ",
        "����", 
});



string ask_for_job()
{
        object ob,obj,me=this_player();
        int i,j,k;
         string dir,msg;
        string meet_room,room;
         mixed *file;
        int lvl = me->query_skill("persuading",1);
        int     qn,exp;
        string  bonus;
/*
        if (!wizardp(me))
        return "����slow�Ը��ˣ��⼸�첻���ô��Ȱ�ܣ�ƶ�����slow ���ҵ�Ǹ����job ���ڿ��š�"; 
*/
        if (me->query("family/family_name")!="������") {
                command ("smile ");
                return RANK_D->query_respect(this_player())+"Ҳ��Ȱ����";
        }
        
        if (me->query_temp("mp_persjob") == 2)
        {
                exp = 180+random(40);
                qn = 70+random(20);
                bonus = sprintf(HIW"�㱾�����񹲵õ�:%d�㾭�飬%d��Ǳ�ܡ�\n"NOR,exp,qn);
                tell_object(me,bonus); 
                command("haha ");
                me->delete_temp("mp_persjob");
                me->add("combat_exp",exp);
                me->add("potential",qn);
                if (me->query("potential") > me->query("max_potential"))
                        me->set("potential",me->query("max_potential"));

                return "�ɵúã����������Ƕ��ҵ��Ӱ���";
        
        }
        if (me->query_temp("mp_persjob") == 1) {
                command ("hmm ");
                return "�ϻؽ����������û�����......";
        }
        if (time()<me->query("mp_job_time")+BUSY_TIME) {
                command ("hehehe ");
                return "�й���ʦ�ĸ����������̫ͦƽ�ġ�";
        }

        if (me->query_skill("persuading",1) < 30)
        {
                return "��Ķ������˻���������";
        }
 
      command ("nod ");
        
        dir = place[0];
        file = get_dir(dir, -1);
        i = sizeof(file);
        if (!sizeof(file) || i<1)
                return "�й���ʦ�ĸ����������̫ͦƽ�ġ�";

        me->set_temp("mp_persjob",1);
        me->set("mp_job_time",time());

        

        for(j = 0; j<=random(i-1);j++ ) {
                if(file[j][0][strlen(file[j][0])-2..strlen(file[j][0])] != ".c") continue; 
                        file[j][0]= replace_string(file[j][0],".c","");
                
        }
        
        msg = sprintf("%s%s",place[0],file[j][0]);

        if (me->query("combat_exp")<100000)
                msg="/d/emei/hz_guangchang.c";
        if (wizardp(me)) tell_object(me,msg);

       meet_room=msg;
       obj=load_object(meet_room);
       room=obj->query("short");
        ob = new("/kungfu/class/emei/rascal");
        setupras(ob,me);
        ob->set("per_mark",me);
        ob->move(meet_room);

        msg = sprintf("������%s��%s���ң��Ǿ��ෳ%s��ȥ����Ȱ��(quanfu)��\n",area[0],room,RANK_D->query_respect(this_player()));
/*
        msg = sprintf("������%s��%s���ң��Ǿ��ෳ��ȥ����Ȱ����\n",area[0],room);
*/
        tell_object(me,msg);
        return "������ȥ?";
/*
        return "������"+area[0]+"��"+room+"���ң��Ǿ��ෳ"+RANK_D->query_respect(this_player())+"��ȥ����Ȱ����";
*/
}

void setupras( object rascal, object me ) 
{ 
        int myexp = me->query( "combat_exp" ); 
        int level = to_int(pow(myexp*10,0.33333)+1); 
        if (me->query("combat_exp") < 100000)
        {
                level = level/2;
        }
        else
        level = level * 5 / 4;
        
        if ( level < 20 ) level = 20; 
        rascal->set_skill( "strike", level ); 
        rascal->set_skill( "cuff", level ); 
        rascal->set_skill( "force", level ); 
        rascal->set_skill( "parry", level*3/2 ); 
        rascal->set_skill( "dodge", level ); 
        rascal->set_skill( "hand", level );
        rascal->set_skill( "qinnashou", level );
        rascal->set_skill( "liuxing-bu", level );
        rascal->map_skill( "hand", "qinnashou" );
        rascal->map_skill( "dodge", "liuxing-bu" );
        rascal->prepare_skill("hand", "qinnashou");

        rascal->set( "max_qi", me->query("max_qi")); 
        rascal->set( "eff_qi", me->query("max_qi")); 
        rascal->set( "qi", me->query( "max_qi" )); 
        rascal->set( "max_neili", me->query( "max_neili" ) ); 
        rascal->set( "neili", me->query( "max_neili" ) ); 
        rascal->set( "max_jingli", me->query( "max_jingli" ) ); 
        rascal->set( "eff_jingli", me->query( "eff_jingli" ) ); 
        rascal->set( "jingli", me->query( "max_jingli" ) );
        if (level > 100)
        rascal->set("jiali",level/2); 
        rascal->set("combat_exp",me->query("combat_exp"));
} 
/*
int do_quanfu(string who)
{
        object me = this_player();
        object target;
        object where = environment(me);
        int     lvl=me->query_skill("persuading",1);
        mixed busy;
        
        if (!me->query_temp("mp_persjob"))
                return notify_fail("���ȥ�����ʦ̫�����ɡ�\n");

        if (!who)
                return notify_fail("��ҪȰ��˭��\n");
        
        target = present(who, environment(me));
        if ( !target || target == me || !living(target) || !objectp(target) ) 
                return notify_fail("����Ȱ��˭��\n");

        if ( busy = me->query_busy() ) {
                if (intp(busy)) me->start_busy(busy+1);
                return notify_fail("��������æ�ţ�\n");
        }
        
        if ( target->query("race") != "����" )
                return notify_fail(target->name() + "�������˻���\n");

        if ( target->query("per_mark")!=target)
                return notify_fail("���ʦ̫��������Ȱ������˰ɡ�\n");

        if ( me->query_temp("new_per") == 1)
                return notify_fail("������Ȱ�����ˡ�\n");

        if (me->query("jingli") < lvl || me->query("jing")<lvl)
                return notify_fail("�������״�����ã�û������Ȱ���ˡ�\n");

       tell_object(me, HIY + "���" + EMOTE_D->normal_color(target->name())
              + "˵����" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR); 

       tell_object(target, HIY + me->name() + "����˵����" +
                persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR);

       message("vision", HIY + me->name() + "��" + EMOTE_D->normal_color(target->name()) 
                + "˵����" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR,
                where, ({ me, target }) );


        me->set_temp("new_per",1);
        me->add("jingli",-(10+random(lvl)));
        me->add("jing",-(10+random(lvl)));

        if (!target->is_fighting())
        {
                message_vision(HIR"$N�ٺ�һЦ������ʲô��������Ȱ����? ���������㡣\n"NOR,target,me);
                target->kill_ob(me);
        }
        call_out("per_end",2+random(4),me,target);


        return 1;
}

int     per_end(object me,object target)
{
        int lvl = me->query_skill("persuading",1);
        int myexp = me->query( "combat_exp" ); 
        int level = to_int(pow(myexp*10,0.33333)+1); 

        if (environment(target) != environment(me)) {
                tell_object(me, "���գ�" + target->name() + "�Ѿ����ˡ�\n"); 
                me->delete_temp("new_per");
                return 1;
        }

        if ( !living(target) || !target ) {
                tell_object(me, target->name() + "�Ѳ�����ȡ���Ȱ���ˣ�\n");
                me->delete_temp("new_per");
                return 1;
        }


        if (random(lvl) > level || random(15) == 0)
        {
                tell_object(target, HIG + "���ܵ�" + me->name()
                                  + "�ĸ��У��������ֲ�����\n" + NOR);
                tell_object(me, HIG + EMOTE_D->normal_color(target->name()) 
                              + "�ܵ���𷨸��У��������ֲ�����\n" + NOR);
              message("vision", CYN"ֻ��" + EMOTE_D->normal_color(target->name()) 
                        + "����һ�ݣ�˵�����ã�" + me->name() 
                        + succeed_msg[random(sizeof(succeed_msg))] + NOR, 
                        environment(target), ( {me, target} ) );

                target->remove_all_killer();
                destruct(target);
                me->delete_temp("new_per");
                me->delete_temp("mp_persjob");


        }
        else
        {
                tell_object(me, RED + EMOTE_D->normal_color(target->name()) + "������һ������"
                                       + RANK_D->query_rude(me) 
                                       + "������£����У���\n" + NOR);
                tell_object(target, CYN + "���" + me->name() + "���һ������"
                                          + RANK_D->query_rude(me)
                                          + "������£����У���\n" + NOR);
                message("vision", CYN + "ֻ��" + EMOTE_D->normal_color(target->name()) + "����"
                                        + me->name() + "���һ������"
                                        + RANK_D->query_rude(me)
                                        + "������£����У���\n" + NOR, environment(target),
                                        ( {me, target} ) );
                me->delete_temp("new_per");

        }
        me->start_busy(1+random(1));
        return 1;
}
*/
