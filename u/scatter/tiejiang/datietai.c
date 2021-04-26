//Code by Scatter
//V 1.2
//3/29/2002

#include <ansi.h>

inherit ITEM;

//#include "/newjob/tiejiang/list.h"
//#define _DES 
 
void create()
{
        set_name(HIY"����̨"NOR,( {"datie tai","datie","tai"} ));
        set_weight(3000);
        if (clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("long","
    ����һ�źܽ�ʵ�Ĵ���̨���������"+HIW+"����ʯ"+NOR+"����̨���ͺܺ������̨�����
�ģ������Ǿ������������������ǵ�һ����Ʒ�ġ��쿴����¯��Ķ����յ���
ô���˰ɣ�����Ҫ����Ŷ��\n");
                set("value",10000);
                set("material","bronze");
                set("no_get",1);
        }
        setup();
}




void init()
{
        add_action("do_fang","fang"); //command for putting
                add_action("do_rong","rong"); //Command for melting the ore
                add_action("do_rong","melt"); //command for melting the ore
                add_action("do_zhu","zhu"); //Command for making
                add_action("do_da","da");
}




int do_fang(string arg)
{
        object me, obj,ob;
        string item, target; 
        int maxstr;


        me = this_player();
        ob = this_object();


                //Test for restrictions.
        if (!arg || sscanf(arg, "%s in %s", item, target) != 2)
            return notify_fail("��Ҫ��ʲô�����Ž����\n");
        
        //Preventing Putting All Items
        if (item == "all" ) 
                return notify_fail("������Ҫ��ʲô, �˷���Դ��\n");
        
                //Incase things got tricked
        if (!objectp(obj = present(item, me)))
                return notify_fail("�����أ�\n");

                
                //Check if item are kuang [Remember insert a value in the "KUANG", set("kuang", 1) ];
        if (!obj->query("kuang"))
                return notify_fail("��û�·�ʲô����ɵĶ�����������ѽ��\n");


                //Accumulating the max points that source provide.
                maxstr = maxstr + obj->query("strvalue");


                //Recording the value to player
                me->set_temp("tiejiang/maxstr", maxstr);


                //Display Action Message
        message_vision("$N��һ"+obj->query("unit")+obj->query("name")+"�ŵ�����̨��\n���Ҫ��ʼ�ܻ������(rong)\n",me);

                //Switch for Checking if items are added
                me->set_temp("tiejiang/itemadd", 1);

                //Destroy Object(As "KUANG")
        destruct(obj);

        return 1;

}



int do_rong(string arg)
{
        object me;
    string item, target; 
        me = this_player();


        //Testing Condition
        if(!me->query_temp("tiejiang/itemadd"))
                return notify_fail("��Ҫ�ܻ�ʲô��\n");


        //Check for Min Neili
        if(me->query("neili") < 300)
                return notify_fail("�����������\n");


        //Check for Min Jingli
        if(me->query("jingli") < 400)
                return notify_fail("��ľ�������\n");


        //Check for Min Qi
        if(me->query("qi") < 100)
                return notify_fail("�㶼�����ˣ��Ļ��а취������\n");

        //Display Message
        message_vision("\n"HIR"���ȵĻ��潫��һ��һ����ܻ��С�\n"NOR,me);


        //Clear the Switch
        me->delete_temp("tiejiang/itemadd");


        //Began to call out functions.
        remove_call_out("rong");
    call_out("rong",5+random(5),me);


        return 1;
}


void rong(object me)
{
    //Define Var.
        int intQi, intJingli, intNeili, skilld, skillt;

        //Display Message
        message_vision("\n"HIY"��$N��ǰ�������ڳ��ٺ�ɫ�������ˡ�\n"NOR,me);
        message_vision("\n"HIW"��������ʱ��ʼ������(zhu)��\n"NOR,me);
        
        skilld = me->query_skill("datieshu") / 10;
        skillt = me->query_skill("tiejiang") / 10;
        
        //Calculate the QI/Jingli/Neili Damage
        intQi = -(random(23) + 75) + skilld;
        intJingli = -(random(100) + 300) + skilld;
        intNeili = -(random(170) + 130) + skilld;

        //Apply Effect
        me->add("qi", intQi);
        me->add("jingli", intJingli);
        me->add("neili", intNeili);
        
        //Set Switch for finish rong item
        me->set_temp("tiejiang/rong", 1);

        //Give Busy time
        me->start_busy(random(5) + 2);

        return;
}


int do_zhu(string arg)
{
        //Define Varible
        object me;
    string item, target; 
        me = this_player();



        //Check if Busy
        if ( me->is_busy() )
                return notify_fail("�㻹��æѽ��\n");
        

        //Check if have done "RONG" process
        if ( !me->query_temp("tiejiang/rong") )
                return notify_fail("��û�С�������Ҫ��ô����ѽ��\n");
        

        //Check for Min QI
        if ( me->query("qi") < 300 )
                return notify_fail("���ǲ�Ҫ������\n");

        //Check for Min Jingli
        if ( me->query("jingli") < 300 )
                return notify_fail("�������������Լ���\n");

        //Check for Min Neili
        if ( me->query("neili") < 300 )
                return notify_fail("�������������\n");

        //Display Message
        message_vision("\n"HIC"�㽫�������뽣��ģ���С�\n"NOR,me);


        //Stop Call Out
        remove_call_out("zhu");

        //Delete Current Temp
        me->delete_temp("tiejiang/rong");

        //Call Function with Time Limit
    call_out("zhu",10+random(6),me);


        return 1;
}


void zhu(object me)
{
        //Define Local Varible
        int intQi, intJingli, intNeili, skilld, skillt;


        skilld = me->query_skill("datieshu") / 10;
        skillt = me->query_skill("tiejiang") / 10;

        //Calculate the Damage to Player
        intQi = -(random(50) + 250) + skilld;
        intJingli = -(random(100) + 200) + skilld;
        intNeili = -(random(20) + 280) + skilld;

        //Display Message
        message_vision("\n"HIM"�����������Կ�ʼ�����ˡ�(da)\n"NOR,me);

        //Add Switch for Zhu
        me->set_temp("tiejiang/zhu", 1);

        //Apply Damage to Player
        me->add("qi", intQi);
        me->add("neili", intNeili);
        me->add("jingli", intJingli);

        //Began to make Player Busy
        me->start_busy(random(15) + 5);


        return;
}

int do_da(string arg)
{
        object me;
        int intSkill, intMaxPt, intMaxPtF;
    string item, target; 
        
        me = this_player();

        //Check if Busy
        if ( me->is_busy() )
                return notify_fail("�㻹��æѽ��\n");

        //Check if have done "ZHU" process
        if ( !me->query_temp("tiejiang/zhu") )
                return notify_fail("��û����������Ҫ��ô����ѽ��\n");
        

        //Check for Min QI
        if ( me->query("qi") < 300 )
                return notify_fail("���ǲ�Ҫ������\n");

        //Check for Min Jingli
        if ( me->query("jingli") < 300 )
                return notify_fail("�������������Լ���\n");

        //Check for Min Neili
        if ( me->query("neili") < 300 )
                return notify_fail("�������������\n");


        //Get data from Player
        intSkill = me->query_skill("datieshu");
        intMaxPt = me->query_temp("tiejiang/maxstr");

        //Calculation
        intMaxPtF = intMaxPt + (intSkill / 5);
        
        //Stop Call Out
        remove_call_out("select_menu");

        //Fake Message
        write("ϵͳ�������յ���Ʒ��\n");
        
                
        //Set the Data into player
        me->set_temp("tiejiang/maxstr", intMaxPtF);

        //Call Function with Time Limit
    call_out("select_menu",1,me);

        return 1;
}

void select_menu(object me)
{
        write("\n******************************************\n");
        write("*      ��ѡ����Ҫ���Ķ��� (V. 1.1)       *\n");
        write("*        ���������� 2/21/2002          *\n");
        write("******************************************\n");
        write("* **************                         *\n");
        write("* *   ��׼��   *                         *\n");
        write("* **************                         *\n");
        write("* 1) һ��˵�                            *\n"); // 1 LVL Limit
        write("* 2) �еȲ˵�                            *\n"); //10 LVL Limit
        write("* 3) �߼��˵�                            *\n"); //30 LVL Limit
        write("* ---------------------------------------*\n");
        write("* 4) һ��ֽ�                            *\n"); // 1 LVL Limit
        write("* 5) �еȸֽ�                            *\n"); //10 LVL Limit
        write("* 6) �߼��ֽ�                            *\n"); //30 LVL Limit
        write("* ---------------------------------------*\n");
        write("* 7) һ��ֵ�                            *\n"); // 1 LVL Limit
        write("* 8) �еȸֵ�                            *\n"); //10 LVL Limit
        write("* 9) �߼��ֵ�                            *\n"); //30 LVL Limit
        write("* ---------------------------------------*\n");
        write("*10) һ�㻤��                            *\n"); // 5 LVL Limit
        write("*11) �еȻ���                            *\n"); //20 LVL Limit
        write("*12) �߼�����                            *\n"); //40 LVL Limit
        write("* ---------------------------------------*\n");
        write("* **************                         *\n");
        write("* *   �Զ���   *                         *\n");
        write("* **************                         *\n");
        write("*13) ��   (Ŀǰ��ʱ�ر�)                 *\n"); // > 50 LVL Limit
        write("*14) ��                                  *\n"); // > 50 LVL Limit
        write("*15) ���� (Ŀǰ��ʱ�ر�)                 *\n"); // > 50 LVL Limit
        write("******************************************\n"); // > 50 LVL Limit
        write("\n enter ѡ��\n");

        add_action("smenu", "enter");


        return;
}


int smenu(string arg)
{
        object me = this_player();
        int uSelect, uLvl;

        uSelect = atoi(arg);
        uLvl = me->query_skill("datieshu");

        remove_action("smenu", "enter");



        switch(uSelect)
        {
                case 1:
                        {
                                if (uLvl >= 1)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 2:
                        {
                                if (uLvl >= 10)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 3:
                        {
                                if (uLvl >= 30)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 4:
                        {
                                if (uLvl >= 1)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 5:
                        {
                                if(uLvl >= 10)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 6:
                        {
                                if(uLvl >= 30)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }


                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 7:
                        {
                                if(uLvl >= 1)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 8:
                        {
                                if(uLvl >= 10)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 9:
                        {
                                if(uLvl >= 30)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 10:
                        {
                                if(uLvl >= 5)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 11:
                        {
                                if(uLvl >= 20)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 12:
                        {
                                if(uLvl >= 40)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 13:
                        {
                                if(uLvl >= 50)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 14:
                        {
                                if(uLvl >= 50)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 15:
                        {
                                if(uLvl >= 50)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("�Բ�����Դ������˽ⲻ���࣬Ŀǰ����ִ�����������\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }
        }


        remove_call_out("processm");
        call_out("processm",1,me);
        
        return 1;
}





void processm(object me)
{
        int intSel;

        intSel = me->query_temp("tiejiang/select");
        me->delete_temp("tiejiang/select");

        switch(intSel)
        {
        case 1:
                {
                        //1) һ��˵�
                        write("���ϴ�����...");
                        remove_call_out("b_caidao");
                        call_out("b_caidao",1,me);
                        break;
                }
        case 2:
                {
                        //2) �еȲ˵�
                        write("���ϴ�����...");
                        remove_call_out("m_caidao");
                        call_out("m_caidao",1,me);
                        break;
                }
        case 3:
                {
                        //3) �߼��˵�
                        write("���ϴ�����...");
                        remove_call_out("a_caidao");
                        call_out("a_caidao",1,me);
                        break;
                }
        case 4:
                {
                        //4) һ��ֽ�
                        write("���ϴ�����...");
                        remove_call_out("b_gangjian");
                        call_out("b_gangjian",1,me);
                        break;
                }
        case 5:
                {
                        //5) �еȸֽ�
                        write("���ϴ�����...");
                        remove_call_out("m_gangjian");
                        call_out("m_gangjian",1,me);
                        break;
                }
        case 6:
                {
                        //6) �߼��ֽ�
                        write("���ϴ�����...");
                        remove_call_out("a_gangjian");
                        call_out("a_gangjian",1,me);
                        break;
                }
        case 7:
                {
                        //7) һ��ֵ�
                        write("���ϴ�����...");
                        remove_call_out("b_blade");
                        call_out("b_blade",1,me);
                        break;
                }
        case 8:
                {
                        //8) �еȸֵ�
                        write("���ϴ�����...");
                        remove_call_out("m_blade");
                        call_out("m_blade",1,me);
                        break;
                }
        case 9:
                {
                        //9) �߼��ֵ�
                        write("���ϴ�����...");
                        remove_call_out("a_blade");
                        call_out("a_blade",1,me);
                        break;
                }
        case 10:
                {
                        //10) һ�㻤��
                        write("���ϴ�����...");
                        remove_call_out("b_armor");
                        call_out("b_armor",1,me);
                        break;
                }
        case 11:
                {
                        //11) �еȻ���
                        write("���ϴ�����...");
                        remove_call_out("m_armor");
                        call_out("m_armor",1,me);
                        break;
                }
        case 12:
                {
                        //12) �߼�����
                        write("���ϴ�����...");
                        remove_call_out("a_armor");
                        call_out("a_armor",1,me);
                        break;
                }
        case 13:
                {
                        //13) ��
                        write("���ϴ�����...");
                        remove_call_out("s_blade");
                        call_out("s_blade",1,me);
                        break;
                }
        case 14:
                {
                        //14) ��
                        write("���ϴ�����...");
                        remove_call_out("s_jian");
                        call_out("s_jian",1,me);
                        break;
                }
        case 15:
                {
                        //15) ����
                        write("���ϴ�����...");
                        remove_call_out("s_armor");
                        call_out("s_armor",1,me);
                        break;
                }
        }

        return;
}


//Basic Caidao
void b_caidao(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("b_caidaoa");
        call_out("b_caidaoa",5 + random(10),me);

        return;
}
void b_caidaoa(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/bcaidao");
        ob->move(me);

        return;
}




//Medium Caidao
void m_caidao(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("m_caidaoa");
        call_out("m_caidaoa",8 + random(10),me);

        return;
}
void m_caidaoa(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/mcaidao");
        ob->move(me);

        return;
}





//Advance Caidao
void a_caidao(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("a_caidaoa");
        call_out("a_caidaoa",10 + random(10),me);

        return;
}
void a_caidaoa(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/acaidao");
        ob->move(me);

        return;
}



//Basic Gangjian
void b_gangjian(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("b_gangjiana");
        call_out("b_gangjiana",5 + random(10),me);

        return;
}

void b_gangjiana(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/bgangjian");
        ob->move(me);

        return;
}



//Medium Gangjian
void m_gangjian(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("m_gangjiana");
        call_out("m_gangjiana",8 + random(10),me);

        return;
}

void m_gangjiana(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/mgangjian");
        ob->move(me);

        return;
}



//Advance Gangjian
void a_gangjian(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("a_gangjiana");
        call_out("a_gangjiana",10 + random(10),me);

        return;
}

void a_gangjiana(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/agangjian");
        ob->move(me);

        return;
}


//Basic Blade
void b_blade(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("b_bladea");
        call_out("b_bladea",5 + random(10),me);

        return;
}

void b_bladea(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/bblade");
        ob->move(me);

        return;
}



//Medium Blade
void m_blade(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("m_bladea");
        call_out("m_bladea",8 + random(10),me);

        return;
}

void m_bladea(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/mblade");
        ob->move(me);

        return;
}



//Advance Blade
void a_blade(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("a_bladea");
        call_out("a_bladea",10 + random(10),me);

        return;
}

void a_bladea(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/ablade");
        ob->move(me);

        return;
}



//Basic Armor
void b_armor(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("b_armora");
        call_out("b_armora",5 + random(10),me);

        return;
}

void b_armora(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/barmor");
        ob->move(me);

        return;
}


//Medium Armor
void m_armor(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("m_armora");
        call_out("m_armora",5 + random(10),me);

        return;
}

void m_armora(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/marmor");
        ob->move(me);

        return;
}


//Advance Armor
void a_armor(object me)
{
        message_vision("\n"HIR"�㿪ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"��Ū��ȫ���Ǻ���\n"NOR,me);
        
        remove_call_out("a_armora");
        call_out("a_armora",5 + random(10),me);

        return;
}

void a_armora(object me)
{
        object ob;

        message_vision("\n"HIC"���ڴ�����ˡ�\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/aarmor");
        ob->move(me);

        return;
}










//********************************************************************
//********************************************************************
//********************** SELF MADE OBJECT START **********************
//********************************************************************
//********************************************************************

void s_blade(object me)
{
        int intMaxPtF;
                intMaxPtF = me->query_temp("tiejiang/maxstr");

                //Display Text
        write("�������Ի��� " + intMaxPtF + " ��(��������������������)\n");
        write("������ѡ����η�������Ҫ�ĵ���\nע��: ������ã����û�п��ԸĵĻ��ᣮ\n\n");
        
        //Ask Dmage Question
        write("ɱ����[20] / ���ö�[25] / ������[20] / ����(Խ��Խ��) [10]\n");
        

        //Print how much points left
        write("������ɱ����: (��ʣ���� " + intMaxPtF + ")[ָ�� - add ����]\n");
        

        //Add new function to pass on data
        add_action("do_damageb", "add");

        return;
}



void s_jian(object me)
{
        int intMaxPtF;
        intMaxPtF = me->query_temp("tiejiang/maxstr");

        //Display Text
        write("�������Ի��� " + intMaxPtF + " ��(��������������������)\n");
        write("������ѡ����η�������Ҫ�ĵ���\nע��: ������ã����û�п��ԸĵĻ��ᣮ\n\n");
        
        //Ask Dmage Question
        write("ɱ����[20] / ���ö�[25] / ������[20] / ����(Խ��Խ��) [10]\n");
        

        //Print how much points left
        write("������ɱ����: (��ʣ���� " + intMaxPtF + ")[ָ�� - add ����]\n");
        

        //Add new function to pass on data
        add_action("do_damage", "add");

        return;
}


void s_armor(object me)
{
        int intMaxPtF;
        intMaxPtF = me->query_temp("tiejiang/maxstr");

        //Display Text
        write("�������Ի��� " + intMaxPtF + " ��(��������������������)\n");
        write("������ѡ����η�������Ҫ�ĵ���\nע��: ������ã����û�п��ԸĵĻ��ᣮ\n\n");
        
        //Ask Dmage Question
        write("��Ӳ��[20] / ���ö�[25] / ����[20] / ����(Խ��Խ��) [10]\n");
        

        //Print how much points left
        write("�������Ӳ��: (��ʣ���� " + intMaxPtF + ")[ָ�� - add ����]\n");
        

        //Add new function to pass on data
        add_action("do_damagea", "add");

        return;
}






//***********************************************************
//***********************************************************
//******************* INPUT FOR SWORD ***********************
//***********************************************************
//***********************************************************

int do_damage(string arg)
{
        //Declear Varible
        object me;
        int intPt, intDamage, intX;
        
        //Define me
        me = this_player();

        //getting data
        intPt = me->query_temp("tiejiang/maxstr");
        
        //Convert Arg Format from String to Int
        intX = atoi(arg);

        //Calculation
        intPt = intPt - intX;

        //Error Checking
        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        //Delete action
        remove_action("do_damage", "add");


        //Calculate damage
        intDamage = 20 + intX;

        me->set_temp("tiejiang/damage", intDamage);
                
        me->set_temp("tiejiang/maxstr", intPt);
        

        write("���������ö�: (��ʣ���� " + intPt + ")[ָ�� - add ����]\n");

        add_action("do_strength", "add");       

        return 1;
}

int do_strength(string arg)
{
        object me;
        int intPt, intStr, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;


        intStr = 25 + intX;

        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        remove_action("do_strength", "add");

        me->set_temp("tiejiang/strength", intStr);
        me->set_temp("tiejiang/maxstr", intPt);

        write("�����������: (��ʣ���� " + intPt + ")[ָ�� - add ����]\n");

        add_action("do_sharp", "add");

        return 1;
}

int do_sharp(string arg)
{
        object me;
        int intPt, intSharp, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        remove_action("do_sharp", "add");

        intSharp = 20 + intX;

        me->set_temp("tiejiang/sharp", intSharp);
        me->set_temp("tiejiang/maxstr", intPt);

        write("����������(Խ��Խ��): (��ʣ���� " + intPt + ")[ָ�� - add ����]\n");

        add_action("do_weight", "add");

        return 1;
}

int do_weight(string arg)
{
        object me;
        int intPt, intWei, intSharp, intStr, intDamage, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");
        intX = atoi(arg);
        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        remove_action("do_weight", "add");

        intWei = 10 + intX;
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");

        me->set_temp("tiejiang/weight", intWei);
        me->set_temp("tiejiang/maxstr", intPt);
        me->delete_temp("tiejiang/zhu");

        write("ɱ����[" + intDamage + "] / ���ö�[" + intStr + "] / ������[" + intSharp + "] / ����(Խ��Խ��) [" + intWei + "]\n");

        message_vision("\n"HIR"$N��ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"$NŪ��ȫ���Ǻ���\n"NOR,me);
        
        
        //Stop Call Out
        remove_call_out("finish");

        //Call Function with Time Limit
    call_out("finish",20+random(6),me);



        return 1;
}

void finish(object me)
{
        int intPt, intWei, intSharp, intStr, intDamage;

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");


        message_vision("\n"HIC"����������ˡ�\n"NOR,me);
        write("�����������Ҫ��ʲô����(Ӣ��)[���� enter ����]��\n");

        add_action("do_name", "enter");
        
        return;

}

int do_name(string arg)
{
        object me;
        me = this_player();

        remove_action("do_name", "enter");
        me->set_temp("tiejiang/wename", arg);

        write("�����������Ҫ��ʲô����(����)[���� enter ����]��\n");

        add_action("do_cname", "enter");
        
        return 1;
}


int do_cname(string arg)
{
        object me, ob;
        int intPt, intWei, intSharp, intStr, intDamage, intdam;
        string strEName, strCName;

        me = this_player();


        remove_action("do_cname", "enter");

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");
        strEName = me->query_temp("tiejiang/wename");
        strCName = arg;
        intdam = intDamage * 2;


        me->set("tiejiang/weight", intWei);
        me->set("tiejiang/sharp", intSharp);
        me->set("tiejiang/strength", intStr);
        me->set("tiejiang/damage", intDamage);
        me->set("tiejiang/adamage", intdam);
        me->set("tiejiang/wname", strCName);
        me->set("tiejiang/wnamee", strEName);


        ob = new("/newjob/tiejiang/obj/ssword");
//      ob->set("name", strCName);
//      ob->set("id", strEName);
        ob->set("long", "ɱ����[" + intDamage + "] / ���ö�[" + intStr + "] / ������[" + intSharp + "] / ����(Խ��Խ��) [" + intWei + "]\n");
        ob->set("tiejiang/weight", intWei);
        ob->set("tiejiang/sharp", intSharp);
        ob->set("tiejiang/strength", intStr);
        ob->set("tiejiang/damage", intDamage);
        ob->set("tiejiang/adamage", intdam);
        ob->set("tiejiang/wname", strCName);
        ob->set("tiejiang/wnamee", strEName);
        
//      ob->set("tiejiang/weight", intWei);
//      ob->set("tiejiang/sharp", intSharp);
//      ob->set("tiejiang/strength", intStr);
//      ob->set("tiejiang/damage", intDamage);
//      ob->apply_damage(intdam);
        ob->move(me);

        message_vision("\n"HIR"$N��������ˣ�������$N�ƺ������⡣\n"NOR,me);    
        me->improve_skill("tiejiang", 5+random(5) ); 
        me->improve_skill("datieshu", 5+random(5) );

        return 1;
}





//***********************************************************
//***********************************************************
//******************* INPUT FOR BLADE ***********************
//***********************************************************
//***********************************************************

int do_damageb(string arg)
{
        //Declear Varible
        object me;
        int intPt, intDamage, intX;
        
        //Define me
        me = this_player();

        //getting data
        intPt = me->query_temp("tiejiang/maxstr");
        
        //Convert Arg Format from String to Int
        intX = atoi(arg);

        //Calculation
        intPt = intPt - intX;

        //Error Checking
        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        //Delete action
        remove_action("do_damageb", "add");


        //Calculate damage
        intDamage = 20 + intX;

        me->set_temp("tiejiang/damage", intDamage);
                
        me->set_temp("tiejiang/maxstr", intPt);
        

        write("���������ö�: (��ʣ���� " + intPt + ")[ָ�� - add ����]\n");

        add_action("do_strengthb", "add");      

        return 1;
}

int do_strengthb(string arg)
{
        object me;
        int intPt, intStr, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;


        intStr = 25 + intX;

        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        remove_action("do_strengthb", "add");

        me->set_temp("tiejiang/strength", intStr);
        me->set_temp("tiejiang/maxstr", intPt);

        write("�����������: (��ʣ���� " + intPt + ")[ָ�� - add ����]\n");

        add_action("do_sharpb", "add");

        return 1;
}

int do_sharpb(string arg)
{
        object me;
        int intPt, intSharp, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        remove_action("do_sharpb", "add");

        intSharp = 20 + intX;

        me->set_temp("tiejiang/sharp", intSharp);
        me->set_temp("tiejiang/maxstr", intPt);

        write("����������(Խ��Խ��): (��ʣ���� " + intPt + ")[ָ�� - add ����]\n");

        add_action("do_weightb", "add");

        return 1;
}

int do_weightb(string arg)
{
        object me;
        int intPt, intWei, intSharp, intStr, intDamage, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");
        intX = atoi(arg);
        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        remove_action("do_weightb", "add");

        intWei = 10 + intX;
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");

        me->set_temp("tiejiang/weight", intWei);
        me->set_temp("tiejiang/maxstr", intPt);
        me->delete_temp("tiejiang/zhu");

        write("ɱ����[" + intDamage + "] / ���ö�[" + intStr + "] / ������[" + intSharp + "] / ����(Խ��Խ��) [" + intWei + "]\n");

        message_vision("\n"HIR"$N��ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"$NŪ��ȫ���Ǻ���\n"NOR,me);
        
        
        //Stop Call Out
        remove_call_out("finish");

        //Call Function with Time Limit
    call_out("finishb",20+random(6),me);



        return 1;
}

void finishb(object me)
{
        int intPt, intWei, intSharp, intStr, intDamage;

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");


        message_vision("\n"HIC"����������ˡ�\n"NOR,me);
        write("�����������Ҫ��ʲô����(Ӣ��)[���� enter ����]��\n");

        add_action("do_nameb", "enter");
        
        return;

}

int do_nameb(string arg)
{
        object me;
        me = this_player();

        remove_action("do_nameb", "enter");
        me->set_temp("tiejiang/wename", arg);

        write("�����������Ҫ��ʲô����(����)[���� enter ����]��\n");

        add_action("do_cnameb", "enter");
        
        return 1;
}


int do_cnameb(string arg)
{
        object me, ob;
        int intPt, intWei, intSharp, intStr, intDamage, intdam;
        string strEName, strCName;

        me = this_player();


        remove_action("do_cnameb", "enter");

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");
        strEName = me->query_temp("tiejiang/wename");
        strCName = arg;
        intdam = intDamage * 2;


        me->set("tiejiang/weight", intWei);
        me->set("tiejiang/sharp", intSharp);
        me->set("tiejiang/strength", intStr);
        me->set("tiejiang/damage", intDamage);
        me->set("tiejiang/adamage", intdam);
        me->set("tiejiang/wname", strCName);
        me->set("tiejiang/wnamee", strEName);


        ob = new("/newjob/tiejiang/obj/sblade");
//      ob->set("name", strCName);
//      ob->set("id", strEName);
        ob->set("long", "ɱ����[" + intDamage + "] / ���ö�[" + intStr + "] / ������[" + intSharp + "] / ����(Խ��Խ��) [" + intWei + "]\n");
        ob->set("tiejiang/weight", intWei);
        ob->set("tiejiang/sharp", intSharp);
        ob->set("tiejiang/strength", intStr);
        ob->set("tiejiang/damage", intDamage);
        ob->set("tiejiang/adamage", intdam);
        ob->set("tiejiang/wname", strCName);
        ob->set("tiejiang/wnamee", strEName);
        
//      ob->set("tiejiang/weight", intWei);
//      ob->set("tiejiang/sharp", intSharp);
//      ob->set("tiejiang/strength", intStr);
//      ob->set("tiejiang/damage", intDamage);
//      ob->apply_damage(intdam);
        ob->move(me);

        message_vision("\n"HIR"$N��������ˣ�������$N�ƺ������⡣\n"NOR,me);    
        me->improve_skill("tiejiang", 5+random(5) ); 
        me->improve_skill("datieshu", 5+random(5) );

        return 1;
}











//***********************************************************
//***********************************************************
//******************* INPUT FOR ARMOR ***********************
//***********************************************************
//***********************************************************

int do_damagea(string arg)
{
        //Declear Varible
        object me;
        int intPt, intDamage, intX;
        
        //Define me
        me = this_player();

        //getting data
        intPt = me->query_temp("tiejiang/maxstr");
        
        //Convert Arg Format from String to Int
        intX = atoi(arg);

        //Calculation
        intPt = intPt - intX;

        //Error Checking
        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        //Delete action
        remove_action("do_damagea", "add");


        //Calculate damage
        intDamage = 20 + intX;

        me->set_temp("tiejiang/damage", intDamage);
                
        me->set_temp("tiejiang/maxstr", intPt);
        

        write("���������ö�: (��ʣ���� " + intPt + ")[ָ�� - add ����]\n");

        add_action("do_strengtha", "add");      

        return 1;
}

int do_strengtha(string arg)
{
        object me;
        int intPt, intStr, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;


        intStr = 25 + intX;

        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        remove_action("do_strengtha", "add");

        me->set_temp("tiejiang/strength", intStr);
        me->set_temp("tiejiang/maxstr", intPt);

        write("�����봿��: (��ʣ���� " + intPt + ")[ָ�� - add ����]\n");

        add_action("do_sharpa", "add");

        return 1;
}

int do_sharpa(string arg)
{
        object me;
        int intPt, intSharp, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        remove_action("do_sharpa", "add");

        intSharp = 20 + intX;

        me->set_temp("tiejiang/sharp", intSharp);
        me->set_temp("tiejiang/maxstr", intPt);

        write("����������(Խ��Խ��): (��ʣ���� " + intPt + ")[ָ�� - add ����]\n");

        add_action("do_weighta", "add");

        return 1;
}

int do_weighta(string arg)
{
        object me;
        int intPt, intWei, intSharp, intStr, intDamage, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");
        intX = atoi(arg);
        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("������������������һ��");

        remove_action("do_weighta", "add");

        intWei = 10 + intX;
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");

        me->set_temp("tiejiang/weight", intWei);
        me->set_temp("tiejiang/maxstr", intPt);
        me->delete_temp("tiejiang/zhu");

        write("��Ӳ��[" + intDamage + "] / ���ö�[" + intStr + "] / ����[" + intSharp + "] / ����(Խ��Խ��) [" + intWei + "]\n");

        message_vision("\n"HIR"$N��ʼ�����ˡ�\n"NOR,me);
        message_vision("\n"HIY"$NŪ��ȫ���Ǻ���\n"NOR,me);
        
        
        //Stop Call Out
        remove_call_out("finisha");

        //Call Function with Time Limit
    call_out("finisha",20+random(6),me);



        return 1;
}

void finisha(object me)
{
        int intPt, intWei, intSharp, intStr, intDamage;

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");


        message_vision("\n"HIC"���ߴ�����ˡ�\n"NOR,me);
        write("�����������Ҫ��ʲô����(Ӣ��)[���� enter ����]��\n");

        add_action("do_namea", "enter");
        
        return;

}

int do_namea(string arg)
{
        object me;
        me = this_player();

        remove_action("do_namea", "enter");
        me->set_temp("tiejiang/wename", arg);

        write("�����������Ҫ��ʲô����(����)[���� enter ����]��\n");

        add_action("do_cnamea", "enter");
        
        return 1;
}


int do_cnamea(string arg)
{
        object me, ob;
        int intPt, intWei, intSharp, intStr, intDamage, intdam;
        string strEName, strCName;

        me = this_player();


        remove_action("do_cnamea", "enter");

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");
        strEName = me->query_temp("tiejiang/wename");
        strCName = arg;
        intdam = intDamage * 2;


        me->set("tiejiang/weight", intWei);
        me->set("tiejiang/sharp", intSharp);
        me->set("tiejiang/strength", intStr);
//        me->set("tiejiang/damage", intDamage);
        me->set("tiejiang/adamage", intdam);
        me->set("tiejiang/wname", strCName);
        me->set("tiejiang/wnamee", strEName);


        ob = new("/newjob/tiejiang/obj/ssword");
//      ob->set("name", strCName);
//      ob->set("id", strEName);
        ob->set("long", "��Ӳ��[" + intDamage + "] / ���ö�[" + intStr + "] / ����[" + intSharp + "] / ����(Խ��Խ��) [" + intWei + "]\n");
        ob->set("tiejiang/weight", intWei);
        ob->set("tiejiang/sharp", intSharp);
        ob->set("tiejiang/strength", intStr);
        ob->set("tiejiang/damage", intDamage);
        ob->set("tiejiang/adamage", intdam);
        ob->set("tiejiang/wname", strCName);
        ob->set("tiejiang/wnamee", strEName);
ob->set("tiejiang/damage", intDamage);
        
//      ob->set("tiejiang/weight", intWei);
//      ob->set("tiejiang/sharp", intSharp);
//      ob->set("tiejiang/strength", intStr);
//      ob->set("tiejiang/damage", intDamage);
//      ob->apply_damage(intdam);
        ob->move(me);

        message_vision("\n"HIR"$N��������ˣ�������$N�ƺ������⡣\n"NOR,me);    
        me->improve_skill("tiejiang", 5+random(5) ); 
        me->improve_skill("datieshu", 5+random(5) );

        return 1;
}