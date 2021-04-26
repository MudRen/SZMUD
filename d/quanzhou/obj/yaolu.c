// Code of ShenZhou
//wzfeng changed 99/11/29
#include <ansi.h>

inherit ITEM;

#include "/clone/drug/drug_list.h"

#define _DES "һֻС�������ҩ¯����ͭ�ʵأ�ģ���žɣ��������һֻ�޿��̻�������\nһ������(lip)������ƫ����һ�ף�¯������һֻ̿�裬���ڵ�ľ̿(coal)\n�������¼ӵġ�\n"
#define _FIRE HIR"\nҩ¯����ȼ�Ż�\n"NOR
#define _OPEN "ҩ¯�����Ѿ��ҿ���\n"
 
void create()
{
        set_name(CYN"ҩ¯"NOR,( {"yao lu","yaolu","lu"} ));
        set_weight(3000);
        if (clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","ֻ");
                set("long",_DES);
                set("value",10000);
                set("material","bronze");
                set("no_get",1);
				set("cure_s",0);
                set("cure_d",0);
                set("cure_n",0);
                set("count",6);
                set("drug","none");
        }
        setup();
}

void init()
{
        add_action("do_open","open");
        add_action("do_addyao","add");
        add_action("do_close","close");
        add_action("do_addwater","dao");
        add_action("do_addwater","pour");
        add_action("do_burn","burn");
        add_action("do_miehuo","mie");
        add_action("do_aoyao","aoyao");
        add_action("do_aoyao","lianyao");
        add_action("do_quyao","qu");
}


int do_open(string arg)
{
        object obj,me;
        me = this_player();
        obj = this_object();

        if (me->is_busy() 
        || me->query_temp("pending/exercising") 
        || me->query_temp("exit_blocked"))
                return notify_fail("��������æ���ء�\n");

        if (arg != "lip")
                return notify_fail("��Ҫ��ʲô��\n");
                
        if (query("open"))
                return notify_fail("�����Ѿ����ˡ�\n");

        if (query("is_burning"))
        {
                message_vision(RED"ֻ����������һ���ҽУ�ԭ��$N��ҩ¯�����֡�\n"NOR,me);
                me->add("qi",-150+random(50),"�������ˡ�");
                set("long",_DES+_FIRE);
				return 1;
        }
        message_vision("$N��ҩ¯���ӽҿ���\n", me);
        set("long",_DES+_OPEN);
        set("open", 1);
        return 1;
}
        

int do_addyao(string arg)
{
        object me, obj,ob;
        string item, target; 
        int s,d,n;
        me = this_player();
        ob = this_object();
        
        if (!query("open"))
                return notify_fail("���ȰѸ��Ӵ򿪰ɡ�\n"); 

        if (!arg || sscanf(arg, "%s in %s", item, target) != 2 )
            return notify_fail("��Ҫ��ʲô�����Ž����\n");
                
	  if (item == "all" ) 
                return notify_fail("��ССҩ¯��ôװ������ô�ණ����\n");
                
        if (!objectp(obj = present(item, me)))
                return notify_fail("�����أ�\n");
                                                                
        if (!obj->query("yaocai"))
                return notify_fail("ҩ¯��ֻ�ܷ�ҩ�ġ�\n");
				if (query("is_burning"))
                return notify_fail("���ѵ�ȼ����Ҫ�Ҷ���\n");
                
        if (query("count") < 1)
                return notify_fail("���ѷ���̫��ҩ���ˡ�\n");
        
        s = obj->query("cure_s");
        d = obj->query("cure_d");
        n = obj->query("cure_n");
        //add by wzfeng
		if(!sizeof(query("drug_list")))
		{
			set("drug_list/1",obj->query("id"));
		}
		else
			set("drug_list/"+(sizeof(query("drug_list"))+1)+"",obj->query("id"));

		


        
        message_vision("$N��һ"+obj->query("unit")+obj->query("name")+"�Ž�ҩ¯��\n",me);
        destruct(obj);
        add("count",-1);
        add("cure_s",s);
		add("cure_d",d);
        add("cure_n",n);
		if (wizardp(me))       
        printf("%d\t%d\t%d\t\n",query("cure_s"),query("cure_d"),query("cure_n"));
        
        set("ready", 1);
        return 1;
}

int do_addwater(string arg)
{
        object ob,me;
        me = this_player();
        if (!query("open"))
                return notify_fail("���ȰѸ��Ӵ򿪰ɡ�\n");
                
        if (arg != "water")
                return notify_fail("��Ҫ���ʲô��\n");
                
        if (!query("ready"))
		 return notify_fail("��Ҫ�տ�ˮ��\n");
                
        if (!present("jiudai", me))
                return notify_fail("����Ҫһ��ˮ����\n");

        ob = present("jiudai",me);      
        if (ob->query("liquid/remaining") < 1)
                return notify_fail(ob->query("name")+"�����ˮ�Ѿ��ù��ˡ�\n");

        if (query("is_burning"))
                return notify_fail("���ѵ�ȼ����Ҫ�Ҷ���\n");
        
        ob->add("liquid/remaining", -1);
        set("water",1);
        message_vision("$N��"+ob->query("name")+"�е���һЩˮ��ҩ¯�\n",me);
        return 1;
}

int do_close(string arg)
{       
        object me;
        me = this_player();
        
		 if (arg != "lip")
                return notify_fail("��Ҫ�ر�ʲô��\n");
                
        if (!(query("open")))
                return notify_fail("�����Ѿ������ˡ�\n");
                
        if (query("is_burning"))
        {
                message_vision(RED"ֻ����������һ���ҽУ�ԭ��$N��ҩ¯�����֡�\n"NOR,me);

                me->add("qi",-150+random(50),"�������ˡ�");
                set("long",_DES+_OPEN+_FIRE);
                return 1;
        }
        message_vision("$N��ҩ¯���ӿ��ϡ�\n", me);
        set("long",_DES);
        set("open", 0);
        return 1;
}

int do_burn(string arg)
{
        object me;
		me = this_player();

        if (arg != "coal")
                return notify_fail("��Ҫ��ȼʲô��\n");
                
        if (!present("fire",me))
                return notify_fail("����ʲô���\n");
                
        if (!(query("ready")))
                return notify_fail("ҩ¯��ʲô��û�С�\n");
                
        if (query("is_burning"))
                return notify_fail("���Ѿ���ȼ�ˡ�\n");
                
        if (query("open"))
                return notify_fail("���ȰѸ��ӸǺðɡ�\n");

        message_vision(RED"$N��̿���ȼ��\n\n"NOR,me);
        message_vision(HIB"����ɫ�Ļ���������������$N����ӳ����ɭ�ֲ���\n"NOR,me);
        set("is_burning", 1);
        
        if (query("open"))
                set("long",_DES+_OPEN+_FIRE);
		else
                set("long",_DES+_FIRE);
        
        remove_call_out("burning");
        call_out("burning",10+random(5),me);
        return 1;
}

int do_miehuo(string arg)
{
        object me;
        me = this_player();
        if (arg != "huo")
                return 0;
                
        if (!(query("is_burning")))
                return notify_fail("��û��ȼ��\n");
                
        message_vision(RED"$N��̿��Ϩ��\n"NOR, me);
        
        if (query("open"))
                set("long",_DES+_OPEN);
        else
		  set("long",_DES);
        set("is_burning", 0);
        set("fire_ready", 0);
        remove_call_out("burning");
        return 1;
}

void burning(object me)
{
        object obj = this_object();

        if (!query("water"))
        {
                set("long","һֻС���������ҩ¯��\n");
                message_vision(HIR"ͻȻ��ҩ¯�ڻ���ʢ������ð����$N��æ����ͷ����\n"NOR,me);
                message_vision(HIR"$Nȡ��ҩ��һ�����Ѿ��ճ�һ�Ž�̿��\n"NOR,me);

                obj->set("open",0);
                obj->set("is_burning",0);
                obj->set("ready",0);
                obj->set("fire_ready",0);
                obj->set("pending",0);
                obj->set("done",0);
				 obj->set("long",_DES);
                obj->set("cure_s",0);
                obj->set("cure_d",0);
       

        obj->set("cure_n",0);
                obj->set("drug","none");
                obj->set("count",6);
                
                return;
        }
        message_vision("\n"HIY"̿�𽥽��������������Կ�ʼ�ˡ�\n"NOR,me);
        set("fire_ready", 1);
        return;
}
        

int do_aoyao()
{
        object me;
        int time,s,d,n,ds,dd,dn,i;
        me = this_player();
        time = 0;

        if (me->is_busy()|| me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("��������æ���ء�\n");

        if (!query("fire_ready"))
                return notify_fail("���δ����\n");
                
        if ((int)me->query("neili") < 1000)
                return notify_fail("����������㣡\n");

        if ((int)me->query("jingli") < 300)
                return notify_fail("��ľ������㣡\n");
                        
        s = query("cure_s");
        d = query("cure_d");
        n = query("cure_n");

if (wizardp(me))
        printf("%d\t%d\t%d\t\n\n--------------------\n",s,d,n);

        for (i=0;i<sizeof(drug_list);i++)
        {
                ds = drug_list[i]["s"];
				 dd = drug_list[i]["d"];
                dn = drug_list[i]["n"];
if (wizardp(me))                
        printf("%d\t%d\t%d\t\n",ds,dd,dn);
                if ( s == ds && d == dd && n == dn )
                {
                        set("drug",drug_list[i]["file"]);
                        time = drug_list[i]["time"];
                        break;
                }
        }
        
        message_vision(HIC"$Nһ�ֿ���¯��һ��һ�ţ��������ٿػ��ƣ�һ����סҩ�ƣ��Ӹ��Ͽ�������\n��ͣ���衣\n"NOR,me);
        message_vision(HIR"\n$N��ͣ���ظ��˶���һ�����������󺹡�\n"NOR,me);
        if (time == 0)
                time = 20;
        if (time > 30)
                me->start_busy(time-random(5)+1);
        else
                me->start_busy((int)(time/2)+1);
        set("pending", 1);
        remove_call_out("finish");
        call_out("finish",time,me);
		  return 1;
}
                        
void finish(object me)          
{
        object obj;
        int gain, neili;
        obj = this_object();
        
        message_vision("\n"HIY"$N����һ������ͣ��������\n"NOR,me);
        me->add("neili",-(700+random(300)));
        me->add("jingli",-random(300));

        neili = (int)me->query("neili");
        gain = (int)(me->query("neili")/1000);  
        if ( (query("drug") != "none") 
        && (me->query("potential") < me->query("max_potential")) ) {

                if( gain > 50 ) {
                        write_file("/log/test/Yaolu",
                        sprintf("%s(%s) has %s neili on %s. \n",
                        me->name(), getuid(me), 
                        chinese_number(neili), ctime(time())) );
						 gain = 20+random(20);
                }

// buwu add for yaolu gain exp check. 2002.05.24
                if (gain>100) gain = 100 + random(10);
                me->add("potential",gain*2);
                me->add("combat_exp",gain);
        }
        
        if (me->query("potential") > me->query("max_potential"))
        me->set("potential",me->query("max_potential"));

        set("done", 1);
        set("pending",0);
}


int do_quyao(string arg)
{       
        object ob,me,obj;
        me = this_player();
        obj = this_object();
        
        if (me->is_busy()
        || me->query_temp("pending/exercising")
		|| me->query_temp("exit_blocked"))
                return notify_fail("��������æ���ء�\n");

        if (arg != "yao")
                return notify_fail("��Ҫȡʲô��\n");

        if (query("pending"))
                return notify_fail("�������˹���ҩ��\n");
                
        if (!(query("done")))
                return notify_fail("��Ҫȡʲô��\n");
                
        if (query("is_burning"))
        {
                message_vision(RED"ֻ����������һ���ҽУ�ԭ��$N��ҩ¯�����֡�\n"NOR,me);
                me->add("qi",-150+random(50),"�������ˡ�");
                return 1;
        }
        
        if (!(query("open")))
                return notify_fail("���ȰѸ��Ӵ򿪰ɡ�\n");
        
        if (!query("drug") || query("drug") == "none")
		  {
                message_vision(HIB"$N��¯һ����¯��֮����һ�Ž���һ��������ûʲô�á�\n"NOR,me);
        }
        else
        {               
			    ob = new(DRUG_D(query("drug")));
//			    ob = new("/clone/drug/buyin-wan");
                message_vision("$N��ҩ¯��ȡ��һ"+ob->query("unit")+ob->query("name")+"\n\n", me);
       log_file("Aoyao_log",sprintf("[%s] %s(%s)����ҩ�ɹ����õ�һ%s\n",ctime(time())[0..15],me->query("name"),me->query("id"),ob->query("unit")+ob->query("name"))); 

//add by wzfeng
				if(ob->query("id")=="buyin wan")
				{
					ob->set("drug_list",query("drug_list"));
				}

                ob->move(me);
                me->start_busy(3);
        }
		delete("drug_list");        
        obj->set("open",0);
        obj->set("is_burning",0);
        obj->set("ready",0);
        obj->set("fire_ready",0);
        obj->set("pending",0);
        obj->set("done",0);
        obj->set("long",_DES);
        obj->set("cure_s",0);
        obj->set("cure_d",0);
        obj->set("cure_n",0);
        obj->set("drug","none");
        obj->set("count",6);
        return 1;
}
