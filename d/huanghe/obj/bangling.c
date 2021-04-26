//Cracked by yujie
// /d/huanghe/obj/bangling.c
// by 13/9/2001

#define BANGZHU   "/d/huanghe/npc/bangzhu"
#define DASHOU    "/d/huanghe/npc/dashou"

#include <ansi.h>
#include <localtime.h>

inherit ITEM;

#include "/d/REGIONS.h"
#include "/d/huanghe/doc/info_store.h"
#include "/d/huanghe/doc/bangskills.h"


void create()
{
        set_name("����", ({ "bang ling", "ling" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����г��õİ��\n");
                set("value", 0);
                set("material", "wood");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
        }
        setup();
}

void init()
{
        add_action("do_collect", "collect");
        add_action("do_sign", "sign");
        add_action("do_find", "find");
        add_action("do_bargain", "bargain");
        add_action("do_huan","huan");
        add_action("do_huan","change");
         add_action("do_sos","sos");
}

int do_find(string arg)
{
        object *obj, room;
        string file, region, fam, result;
        int i;
        mapping job;
        object me = this_player();

        if( (string)query("owner") != this_player()->query("id") ) {
               write("�����Լ��İ���ܲ��ã������뿪���ɡ�\n");
               return 1;
        }

        if( !stringp(fam = this_player()->query_temp("bangs/fam")) ) {
               write("��û�м����ᡣ\n");
               return 1;
        }

        if( arg == "score" ) {
                write("ĿǰΪֹ��һ��������" + chinese_number((int)me->query("clbscore")) + "�㹦�͵㡣\n");
                return 1;
        }

        if( arg != "job" ) {
                write("����Բ�ѯ���У�job��score��\n");
                return 1;
        }

        if( !mapp(job = query("job")) ) {
                write("������û�б�ָ�ɰ���\n");
                return 1;
        }

        result = "�㵱ǰ�İ�����";
        switch(job["type"]) {
        case "Ѱ":
                result += "��" + job["name"]; 
                break;
        case "ɱ":
                result += "ɱ" + job["area"] + "��" + job["name"]; 
                break;
        case "̯��":
                result += "Ҫ" + job["name"] + "��̯��";
                break;
        case "����":
                result += "��" + job["name"] + "����";
                break;
        case "ʾ��":
                result += "��" + job["name"] + "ʾ��";
                break;
        case "����":
                result += "�����" + job["area"] + "��" + job["title"];
                break;
        case "����":
	        result += "���Ͱ�����" + job["dest"];
                break;
        case "����":
                result += "��" + job["name"] + "�����ü�Ǯ";
                break;
        case "���":
                result += "���챦�������";
                break;
	default:
                write("������û�б�ָ�ɰ���\n");
                return 1;
        }

        write(result + "��\n");
        return 1;     
}

int do_collect(string arg)
{
        object me = this_player();
        object victim, obj, obnpc,ft;
        int ap, dp, myexp, yourexp, bonus, record,level,i;
        string  bc_skills, *weapons, *bc_enskills ,weapon_skills,sp_skills;
        mapping job;
        int addscore;

        if( time() < (int)query("collect_time") + random(10) )
                return notify_fail("��������Ҫ��Ǯ��\n");

        if( (int)me->query("jingli") < 50 || (int)me->query("jing") < 50 )
                return notify_fail("��̫���ˣ���Ъ�����\n");

        if( (string)query("owner") != me->query("id") )
                return notify_fail("��������Ϲ�ã�\n");

        if( (string)query("fam") != me->query_temp("bangs/fam") )
                return notify_fail("���Ѿ����Ǵ˰�����ˡ�\n");

        if( !mapp(job = query("job")) )
                return notify_fail("������û�а������\n");

        if( job["type"] != "̯��" )
                return notify_fail("�㵱ǰ�İ�������̯�ѡ�\n");

        if( base_name(environment(me)) != job["place"] )
                return notify_fail("�㻹û��" + job["name"] + "��ʲô̯�ѣ�\n");

        if( !arg )
                return notify_fail("��Ҫ��˭����Ǯ��\n");

        if( !(victim = present(arg, environment(me))) )
                return notify_fail("���û������ˡ�\n");

        if( victim->name() != job["boss"] )
                return notify_fail("���Ҵ����ˡ�\n");

        if( !living(victim) )
                return notify_fail("�㻹�ǵȴ���������������Ǯ�ɡ�\n");

        if( victim->is_busy() || victim->is_fighting() )
                return notify_fail("������æ�š�\n");

        message_vision(HIR"\n$N��$n����ߺ�ȵ�������" + (string)query("fam") + "����̯�ѵģ�ʶʱ��ĸϿ��Ǯ������\n"NOR, me, victim);

        me->receive_damage("jingli", 20 + random(10));
        me->receive_damage("jing", 20 + random(10));

        set("collect_time", time());
        myexp = (int)me->query("combat_exp");
      
              
        if ((int)this_object()->query("job/is_kill")==1) 
        {
          if (ft=present("fighter",environment(victim)))
            if (ft->query("killob")==me)
            { write("�Ȱ���ǰ�Ĵ��ָɵ���˵�ɡ�\n");
             return 1;
            }     
     
          if (me->query("job/killer")=="me")
          {
                 
            message_vision("$N��$n˵����" + RANK_D->query_respect(me) + "��ȻӢ���˵ã���һ��̯����С�ĸø��ġ�\n", victim, me);
            message_vision("$N����˵����" + RANK_D->query_respect(me) + "����ģ����������˽�Ǯ�͵�������\n", victim);
    
            bonus = 60 + random(15);
            addscore=query("score")/10000;
            if (addscore>30) addscore=30;
            bonus = bonus + addscore;
            
            record = bonus * 3 + random(bonus/2);
            me->add("combat_exp", record);
            log_file("test/BangJob", sprintf("%s��%sʱ����̯�ѵ�%s�����\n", me->query("name"), ctime(time()), chinese_number(record)));
            tell_object(me,HIW"����ι������õ�"+chinese_number(bonus)+"�㹦�͵㣬" + chinese_number(record)+ "�㾭��ֵ��\n"NOR);
            me->add("clbscore",bonus);
            delete("job");
            return 1;
          }
          message_vision("$N��$n˵����" + RANK_D->query_respect(me) + "�������Լ���û�б���Ӯ��С�˲�����̯������ôҲ���ύ�ġ�\n",victim,me);
          return 1;
        }
             
        if ((random(me->query("combat_exp"))/1000)>10)
        {
           obnpc = new(DASHOU);
           obnpc->set("killob",me);
           obnpc->start_call();
           obnpc->move(environment(me));
           set("job/is_kill",1);
           obnpc->set("combat_exp", myexp);
           level = ceil( pow( to_float(myexp) * 10.0, 0.333333) ) * 4 / 5;

           obnpc->set("max_qi",    level * 8 + 100);
           obnpc->set("max_jing",  level * 5 + 100);
           obnpc->set("qi",    level * 8 + 100);
           obnpc->set("jing",  level * 5 + 100);
           obnpc->set("max_neili", level * 6 + 200);
           obnpc->set("neili",     level * 6 + 200);
           obnpc->reincarnate();
           obnpc->clear_condition();
           

           obnpc->set_skill("dodge", level);
           obnpc->set_skill("force", level);
           obnpc->set_skill("parry", level);

           bc_skills = keys(unarmed_skills)[random(sizeof(keys(unarmed_skills)))];
           bc_enskills=unarmed_skills[bc_skills];
           sp_skills=bc_enskills[random(sizeof(bc_enskills))];
           obnpc->set_skill(bc_skills, level);
           obnpc->set_skill(sp_skills,level);
           obnpc->map_skill(bc_skills,sp_skills);
           obnpc->prepare_skill(bc_skills,sp_skills);
           obnpc->map_skill("parry", sp_skills);

        
           i = random(sizeof(info_weapon));
           obnpc->set_skill(info_weapon[i]["type"], level);
           weapon_skills=info_weapon[i]["skills"][random(sizeof(info_weapon[i]["skills"]))];
           obnpc->set_skill(weapon_skills,level);
           obnpc->map_skill(info_weapon[i]["type"],weapon_skills);

           level /= 3;
           obnpc->set_temp("apply/defense", level);
           obnpc->set_temp("apply/armor",   level);
           obnpc->set_temp("apply/damage",  level);
           obnpc->set_temp("apply/attack",  level);

           if( !random(2) ) {
                weapons = info_weapon[i]["weapons"];
                obnpc->carry_object(weapons[random(sizeof(weapons))])->wield();
           }
           
        message_vision("$N��Ȼ�����г�һ��ǿ��Ĵ��֣���$n��Ц�������ձ����ѣ�������������λ�ֵܡ�\n", victim, me);
        message_vision(HIY"ֻ��һ��ʮ���׺�Ĵ��ֺ���һ���ܵ�$N����ǰ�����֡�\n"NOR, me);
        message_vision(HIY"$N�ִ�֮�䱻���˸����ֲ������Ǳ����м��š�\n"NOR, me);        
        obnpc->kill_ob(me);
        
        return 1;
  
        }
        
        ap = (int)query("combat_exp") + myexp * 10;

        yourexp = (int)victim->query("combat_exp");
        if( yourexp < 30000 ) yourexp = 30000;
        dp = yourexp * 30;

        
        
        if( random(ap + dp) < dp ) {
                message_vision("$N��ŭ����ʲô" + (string)query("fam") + "���������������\n", victim);
                return 1;
        }
        
        message_vision("$N��$n˵����" + RANK_D->query_respect(me) + "�����ˣ���һ��̯����С�ĸø��ġ�\n", victim, me);
        message_vision("$N����˵����" + RANK_D->query_respect(me) + "����ģ����������˽�Ǯ�͵�������\n", victim);

        bonus = 40 - me->query("combat_exp")/100000;
        if (bonus<10)  bonus=10;
        addscore=query("score")/5000;
        if (addscore>30) addscore=30;
        bonus = bonus + addscore;
        record = bonus*2 + random(bonus);
        me->add("combat_exp", record);
        log_file("test/BangJob", sprintf("%s��%sʱ����̯�ѵ�%s�����\n", me->query("name"), ctime(time()), chinese_number(record)));

        tell_object(me,HIW"����ι������õ�"+chinese_number(bonus)+"�㹦�͵㣬" + chinese_number(record)+ "�㾭��ֵ��\n"NOR);
        me->add("clbscore",bonus);                  
        delete("job");
        return 1;
}

int do_sign(string arg)
{
        object obj, room;
        object me = this_player();
        int bonus, record;
        mapping job;
        int addscore;

        if( query("owner") != me->query("id") )
                return 0;

        if( (string)query("fam") != (string)me->query_temp("bangs/fam") )
                return 0;

        if( !arg || arg != "corpse" || !(obj = present(arg, environment(me))) )
                return notify_fail("��Ҫ����������ǣ�\n");

        if( !mapp(job = query("job")) ) {
                tell_object(me, "������û�а���\n");
                return 1;
        }

        if( stringp(obj->query("my_killer")) && obj->query("my_killer") != me->query("id") )
        {	tell_object(me, "����˲���������ɱ���ġ�\n");
        	return 1;
        }
        
        if  ( obj->query("signed") )
        {	tell_object(me, "ʬ�������Ѿ���������ˡ�\n");
        	return 1;
        }
        
        if  ( (string)obj->query("victim_name") != job["name"] )
        {	tell_object(me, "�ⲻ����Ҫɱ���˵�ʬ�塣\n");
        	return 1;
        }

        if( !( room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");

        if( me->query("id") == room->query("winner") ) {
                tell_object(me, "�����������õĶ�����\n");
                return 1;
        }

        obj->set("signed", 1);
        bonus = job["bonus"] + random(job["bonus"]);
        addscore=query("score")/5000;
        if (addscore>30) addscore=30;
        bonus = bonus + addscore;
        
        record = bonus*2 + random(bonus/2*3);
        me->add("combat_exp", record);
        log_file("test/BangJob", sprintf("%s��%sʱɱ%s��%s�����\n", me->query("name"), ctime(time()), job["name"], chinese_number(record)));

        message_vision("$N��ʬ����д�¡���" + (string)query("fam") + "Ϊ����ɱ�����������֡�\n", me);
        tell_object(me,HIW"����ι������õ�"+chinese_number(bonus)+"�㹦�͵㣬" + chinese_number(record)+ "�㾭��ֵ��\n"NOR);
        me->add("clbscore",bonus);
        delete("job");
        return 1;
}

int do_bargain(string arg)
{
        object target, obj, me = this_player();
        mapping job;
        int bonus, exp,price,okprice;

        
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("����æ���ء�\n");
                
        if (query("owner") != me->query("id"))
                return notify_fail("��������Ϲ�ã�\n");

        if( (string)query("fam") != me->query_temp("bangs/fam") )
                return notify_fail("���Ѿ����Ǵ˰�����ˡ�\n");

        if( !mapp(job = query("job")) )
                return notify_fail("������û�а������\n");
	
	if ( job["type"] != "����" )
		return notify_fail("�����ڵİ�������������\n");
		
        if( !arg )
                return notify_fail("��Ҫ��˭�ּۻ��ۣ�\n");

        if( !(target = present(arg, environment(me))) )
                return notify_fail("���û������ˡ�\n");

        if( !living(target) )
                return notify_fail("�����������û���Ӻ����������ġ�\n");

        if( userp(target) )
                return notify_fail("��Ҳ�����ü�Ǯ�ġ�\n");

        if( target->query("race") && target->query("race") != "����" )
                return notify_fail("���������࣬�����һ�㣡\n");

        if( target->is_busy() || target->is_fighting() )
                return notify_fail(target->name() + "��æ�š�\n");

        if( (exp = (int)target->query("combat_exp")) < 20000 ) {
                message_vision("$N���˰���˵�������������������˰ɡ�\n", target);
                return 1;
        }

        if( !(obj = present(job["good"], me)) )
                return notify_fail("���" + job["name"] + "��Ū���ˡ�\n");

        if( time() < (int)target->query("trader/time") + 600 ) {
                message_vision("$N ���˰���˵�����Ҹ�����һ" + obj->query("unit") + obj->name() + "��\n", target);
                return 1;
        }
        
        if( explode(base_name(environment(target)), "/")[1] == "forest" )
        	return notify_fail("��������ô���ñ���Ķ������Լ��ĵ���������\n");
        
        if( explode(base_name(environment(target)), "/")[1] == query("job/place") )
        	price=obj->query("highprice");
        else
        	price=obj->query("lowprice");
        
        if (me->query("jingli")<30)
        	return notify_fail("��������һ�¾����ٺͱ����ּۻ��۰ѡ�\n");
        
        me->receive_damage("jingli",20);
                
        okprice=price/4+random(price);
        
        if (!stringp(query("job/bargainman")) || query("job/bargainman")!= target->query("name"))
        {      	message_vision("$N��$n˵������������"+ obj->query("unit") + obj->name() + "��֪�����ܳ���ʲô�ۡ�\n",me, target);
        	message_vision("$N��ϸ������һ���󣬴���������ֻ�ܳ�"+chinese_number(okprice)+"�����ӣ��еĻ��ͳɽ�(trade)�ɡ�\n",target);
        }else
        {	message_vision("$N��$n˵������������ϺõĻ�ɫѽ�������Ǯ�ǲ��ǵ��˵�ѽ��\n",me,target);
        	message_vision("$N���ͷ���˵�������ھ�"+chinese_number(okprice)+"����������ۣ����Ļ��ͳɽ�(trade)������������\n",target);
        }
        set("job/bargainman",target->query("name"));
        set("job/price",okprice);
        remove_action("do_trade","trade");
        add_action("do_trade","trade");
        me->start_busy(3);
        return 1;
}

int do_trade(string arg)
{
        object target, obj, me = this_player(),obgold;
        mapping job;
        int bonus,exp,okprice,numb;
        int addscore;

        if( me->is_busy() || me->is_fighting() )
                return notify_fail("����æ���ء�\n");
                
        if (query("owner") != me->query("id"))
                return notify_fail("��������Ϲ�ã�\n");

        if( (string)query("fam") != me->query_temp("bangs/fam") )
                return notify_fail("���Ѿ����Ǵ˰�����ˡ�\n");

        if( !mapp(job = query("job")) )
                return notify_fail("������û�а������\n");

        if( !arg )
                return notify_fail("��Ҫ��˭�ɽ���\n");

        if( !(target = present(arg, environment(me))) )
                return notify_fail("���û������ˡ�\n");

        if( !living(target) )
                return notify_fail("�����������û���Ӻ����������ġ�\n");

        if( userp(target) )
                return notify_fail("��Ҳ�����ü�Ǯ�ġ�\n");

        if( target->is_busy() || target->is_fighting() )
                return notify_fail(target->name() + "��æ�š�\n");

        if( (exp = (int)target->query("combat_exp")) < 20000 ) {
                message_vision("$N���˰���˵�������������������˰ɡ�\n", target);
                return 1;
        }

        if( !(obj = present(job["good"], me)) )
                return notify_fail("���" + job["name"] + "��Ū���ˡ�\n");

        if( time() < (int)target->query("trader/time") + 600 ) {
                message_vision("$N ���˰���˵�����Ҹ�����һ" + obj->query("unit") + obj->name() + "��\n", target);
                return 1;
        }
        
        if (query("job/bargainman") != target->query("name"))
                return notify_fail("�����û���������ۣ���ô�ɽ���\n");
        
        message_vision("$Nˬ���˵�����ðɣ��������Ǯ�ɽ��ˡ�ϣ�������Ժ��л����������⡣\n",me);
        message_vision("����$N��"+obj->query("unit") + obj->name() + "����$n��\n", me, target);
        message_vision("$N���˵�ͷ��˵�����´ι������ʱ���ٸ��\n", target);
        
        target->set("trader/time", time());
       
        bonus = 30+((int)query("job/price") - (int)obj->query("lowprice"))/((int)obj->query("lowprice")/20);
        addscore=query("score")/5000;
        if (addscore>30) addscore= 30;
        bonus = bonus + addscore;
        if (bonus<28)
        {	write("�汿���������������������\n");
        	destruct(obj);
        	delete("job");
        	remove_action("do_trade","trade");
        	return 1;
        }
        else
        {	write("���������׬���ˡ�\n");
        	numb=((int)query("job/price")-(int)obj->query("lowprice"))/200;
        	if ( numb > 0)
        	{	write("��͵͵���룺׬����ô�࣬�Լ��õ��ܹ�Ҳ���ֲ��˵ġ�\n");
        		obgold=new("/clone/money/gold");
        		obgold->set_amount(numb);
        		obgold->move(me);
        		message_vision("$N�ٺټ�Ц�Ű�"+chinese_number(numb)+"�������������Լ��Ļ��С�\n",me);
        	}
        }
        exp=bonus*2+random(bonus/2);
        me->add("combat_exp",exp );
        tell_object(me,HIW"����ι������õ�"+chinese_number(bonus)+"�㹦�͵㣬" + chinese_number(exp)+ "�㾭��ֵ��\n"NOR);
        
        log_file("test/BangJob", sprintf("%s��%sʱ����%s��%s�����\n", me->query("name"), ctime(time()), obj->name(), chinese_number(exp)));
      
	me->add("clbscore",bonus);
        destruct(obj);
        delete("job");
        remove_action("do_trade","trade");
        return 1;
}

int do_huan(string arg)
{	int bef,aft,left;
	object me=this_player();

	if (query("owner") != me->query("id"))
                return notify_fail("��������Ϲ�ã�\n");

        if( (string)query("fam") != me->query_temp("bangs/fam") )
                return notify_fail("���Ѿ����Ǵ˰�����ˡ�\n");
                
        if (!arg || sscanf(arg,"%d",bef)!= 1)
        	return notify_fail("��ȷָ���ʽ��huan <�����һ��Ĺ��͵���>\n");
        
        if (bef < 1)
        	return notify_fail("�����һ��Ĺ��͵�����������㡣\n");
        
        if ( me->query("clbscore")< bef)
        	return notify_fail("��ӵ�еĹ��͵��������һ���\n");
                
        me->add("clbscore",-bef);
        me->add("potential",bef);
        write("�㽫"+chinese_number(bef)+"�㳤�ְ﹦�͵�һ���Ǳ�ܡ�\n");
        log_file("ConvertLog", sprintf("%s(%s)�� %s ʱ�� %s �㹦�͵�һ���Ǳ��\n", me->query("name"), me->query("id"), ctime(time()), chinese_number(bef)));
        write("С��ת����Ǳ�ܳ������ޱ��뾡��ѧ�꣬�����˳���ϷǱ�ܻ���ġ�\n");
        return 1;
}
        
int do_sos(string sos)
{
        object ling = this_object(), user = this_player();
        mapping ling_info;
        string *klist, text = "";
        if(!sos) return 0;
        if(sos != "clb") return 0;
        ling_info = (mapping)ling->query_entire_dbase();
        klist = keys(ling_info);
        klist = sort_array(klist, "sort_keys", ling);
        for(int loop = 0; loop < sizeof(klist); loop++)  {
                if(strlen(klist[loop]) > 7)  text += klist[loop] + "\t: ";
                else text += klist[loop] + "\t\t: ";
                text +=sprintf("%O \n",ling_info[ klist[loop] ]); 
                }
        text += "\n\n";
        log_file("debug/clb", user->query("name") + "(" + user->query("id") + ")����clb������Ϣ���£�\n"
        + text);
        "/cmds/usr/sos"->main(user);
        return 1;
}

