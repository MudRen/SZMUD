//������
//snowlf  by 2001.10.10



#include <ansi.h>

inherit ITEM;
inherit F_SAVE;
inherit F_CLEAN_UP;

int cure_ob(string);
int do_esf(string argg);
int do_egg(string argg);
int do_ewx(string argg);
int do_ebl(string argg);


int intgg;
int intsf;
int intbl;
int intnl;
int intwx;

void init();

void create()
{
        set_name(HIB "������" NOR, ({"poli dan", "puoli", "dan"}));
        set("long", HIW"     һ�ŵ���ɫ��Сҩ�裬��˸�ž�Ө�Ĺ�������Ǵ�˵���ܹ���
����̥���ǣ�ϴ�ĸ��棬�������˵��������ˡ������˽���������
���������飬�뿴����(help help_pldan)"NOR"\n\n");
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("value", 50000);
                set("no_sell", 1);
                set("medicine", 1);
        }

        setup();
}

int cure_ob(object me)
{
//    object me;
//   me = this_player();
    
    if((string)me->query("fupldan")=="yes")
    {
    		write(HIR "������ÿ�����ֻ�ܷ���һ�Σ�����ǰ���ù����������ٴη����ˣ�\n");
    		return 1;
    }
    else
    {  
	    	write(HIW "\n\n\n\n\n\n������ V 2.0A\n
	    	------------------------------------\n
	   	1. ĳһ�������츳�������㡣\n
	    	2. ���·������е������츳��������ֵ���ٶ���\n
 	   	3. ������ʮ���Ļ����ڹ���\n
 	   	4. ���ס����޷�ȫ���ɵĵ�ʿ���������ɵĺ��У���ѩɽ�ɵ����\n
 	   	5. �����ƶ��Լ�����\n
 	   	6. ������ÿ�����ֻ�ܷ���һ�Σ����ù�����Զ�������ٴη��ã�
 	   	   ���������Ժ��ٷ�����ѡ6 \n
 	   	------------------------------------\n\n
 	   	����Ҫ��������Ч���أ����������Ӧ�����ִ��룩\n
 	   	" NOR);

  	  	add_action("do_one", "1");
  	  	add_action("do_two", "2");
  	  	add_action("do_three", "3");
  	  	add_action("do_four", "4");
 	   	add_action("do_five", "5");
 	   	add_action("do_six", "6");

 		return 1;
    }
}



int do_one()
{
    object me;
    me = this_player();


    remove_action("do_one", "1");
    remove_action("do_two", "2");
    remove_action("do_three", "3");
    remove_action("do_four", "4");
    remove_action("do_five", "5");

    write(HIW "\n\n\n\n\n������\n
    1. ������������������������\n
    2. ���ǣ���������������ǡ�\n
    3. ��������������������\n
    4. ���ԣ����������������ԡ�\n\n
    ��ѡ��\n
    " NOR);

    add_action("do_bl", "1");
    add_action("do_gg", "2");
    add_action("do_sf", "3");
    add_action("do_wx", "4");

    return 1;

}


           int do_bl()
           {
               int cbl;
               int fbl;

               object me;
               me = this_player();

               remove_action("do_bl", "1");
               remove_action("do_gg", "2");
               remove_action("do_sf", "3");
               remove_action("do_wx", "4");


               cbl = me->query("str", 1);
               fbl = cbl + 2;

               me->set("str", fbl);	
               me->set("jingli", (int)me->query("max_jingli"));
               me->set("fupldan", "yes");
               message_vision(HIY "����ӯ����$N������������ֻ���û����Ǿ�����ʱ�Ե�ǿ׳����࣡\n" NOR, me);
	
//             me->unconcious();
               destruct(this_object());
               return 1;
           }





           int do_gg()
           {
               int cgg;
               int fgg;
               object me;
               me = this_player();


               remove_action("do_bl", "1");
               remove_action("do_gg", "2");
               remove_action("do_sf", "3");
               remove_action("do_wx", "4");

               cgg = me->query("con", 1);
               fgg = cgg + 2;

               me->set("con", fgg);
               me->set("fupldan", "yes");
               message_vision(HIY "$N������һö�������������ƺ����ĵķ�����Щ�仯��\n $Nֻ�о���������֮�������ҧ�������ܣ��Ѳѻ�����ʹ����ʶģ��....\n" NOR, me);
               me->unconcious();
               destruct(this_object());
               return 1;
           }



           int do_sf()
           {
               int csf;
               int fsf;

               object me;
               me = this_player();

               remove_action("do_bl", "1");
               remove_action("do_gg", "2");
               remove_action("do_sf", "3");
               remove_action("do_wx", "4");


               csf = me->query("dex", 1);
               fsf = csf + 2;

               me->set("dex", fsf);
               me->set("fupldan", "yes");
               message_vision(HIY "$N������һö���������ǽ�žž���죬�پ��������࣬\n$N��һ����������ĸо���\n" NOR, me);
//             me->unconcious();
               destruct(this_object());
               return 1;
           }



           int do_wx()
           {
               int cwx;
               int fwx;

               object me;
               me = this_player();

               remove_action("do_bl", "1");
               remove_action("do_gg", "2");
               remove_action("do_sf", "3");
               remove_action("do_wx", "4");


               cwx = me->query("int", 1);
               fwx = cwx + 2;

               me->set("int", fwx);
               me->set("fupldan", "yes");
               message_vision(HIY "$N������һö���������е���ʶ���.... \n$N�͵Ĵ���һ�¼��裬����ͻȻһƬ�������˿���ȥ�Ե��������ࡣ\n" NOR, me);
//             me->unconcious();
               destruct(this_object());

               return 1;
           }






int do_two()
{
int cwx;
int cgg;
int cbl;
int cst;


int arg;
object me;
me = this_player();

    remove_action("do_one", "1");
    remove_action("do_two", "2");
    remove_action("do_three", "3");
    remove_action("do_four", "4");
    remove_action("do_five", "5");

	cwx = me->query("int", 1);
	cgg = me->query("con", 1);
	cbl = me->query("str", 1);
	cst = me->query("dex", 1);


    printf(BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(me), me->short(1));

    write("���ԭ���������츳Ϊ��"HIW" ������" + cbl+" ���ԣ�"+ cwx+" ���ǣ�"+ cgg+" ����"+ cst+"\n\n");
    write(HIW "\n�������츳 (��ʽ�� enter <����> <����> <����> <��>\n");
    write(HIW "(ע�⣺ÿ���츳������15��30֮�䣬�������츳���ܺ�Ӧ����ԭ�������츳֮����2.\n");
    write(HIW " ���ӣ�enter 20 20 20 20\n");
    add_action("do_ebl", "enter");
    return 1;
}



               int do_ebl(string argg)
               {  
		int cwx;
		int cgg;
		int cbl;
		int cst;
               	              	
		int arg;
		int cinttotal;
		int inttotal;
		object me;
		me = this_player();
               	
		cwx = me->query("int", 1);
		cgg = me->query("con", 1);
		cbl = me->query("str", 1);
		cst = me->query("dex", 1);
     
                                
               		sscanf(argg,"%d %d %d %d", intbl,intwx,intgg,intsf);
               		cinttotal = cwx + cgg + cbl + cst - 2;
               		inttotal = intbl + intgg + intwx + intsf;
               	   
                	if (intbl < 15 ||intbl > 30 || intgg < 15 || intgg > 30 || intwx < 15 || intwx > 30 || intsf < 15 || intsf > 30 || inttotal > cinttotal ||inttotal < cinttotal)
                	{
                       		write(HIW "\n���������������, ��������һ��\n");
                       		write(HIW "ע�⣺ÿ���츳������15��30֮�䣬�������츳���ܺ�ӦΪ "+ cinttotal+"(������ԭ�������츳֮����2)\n");
                       		add_action("do_ebl", "enter");
                       		return 1;

                	}

               		else
                	{

                              	me->set("int", intwx);
                                me->set("con", intgg);
                                me->set("str", intbl);
                                me->set("dex", intsf);                                
                                me->set("fupldan", "yes");
                                message_vision(HIY "$N���������ɵ������巢���˷��츲�صı仯��\n��������̥���ǣ�������������һ���ˡ�\n" NOR, me);
                                me->unconcious();
                                destruct(this_object());
                                return 1;
                         }
                }



int do_three()
{
    int ccforce;
    int fforce;
    object me;
    me = this_player();


    ccforce = me->query_skill("force",1);
    fforce = ccforce + 40;

    me->set_skill("force", fforce);
    me->set("fupldan", "yes");
    message_vision(HIY "$N���������ɵ�����ͨ�˳�������ʮ����Ϊ���ܴ�ͨ��{��],{��]���������������\n$N�Ļ����ڹ�ͽȻ������40����\n" NOR, me);
    me->unconcious();
    destruct(this_object());
    return 1;
}



int do_four()
{
    object me;
    me = this_player();

    remove_action("do_one", "1");
    remove_action("do_two", "2");
    remove_action("do_three", "3");
    remove_action("do_four", "4");
    remove_action("do_five", "5");
    
    
    
    if( me->query("class")=="taoist" || me->query("class")=="bonze" || me->query("class")=="lama" )
    {
   
    		if (me->query("family/family_name") == "ȫ���" )
    		{
    		
			write(HIW "����ȫ��̵ĵ�ʿ������ʹ���������ף�����ȥ���ƽ����˰ɣ�\n");
			return 1;
    		}
    		
    		else if (me->query("family/family_name") == "������" )
    		{
    		
			write(HIW "�����ӷ����������ɵĺ��У�����ʹ���������ף�\n");
			return 1;
    		}
    		
    		else if (me->query("family/family_name") == "ѩɽ��" )
     		{
    			write(HIW "�����ӷ�����ѩɽ�ɵ��������ʹ���������ף�\n");
			return 1;
   		}  
   		 
    		else 
    		{
    		    	me->delete("class", "taoist"); 
			me->delete("class", "bonze");  
			me->delete("class", "lama"); 
			me->set("fupldan", "yes");
			message_vision(HIY "$N�Ļ�װ�������³�Ϊ�˷��������е�һԱ���������������ɵ�Լ����\n" NOR, me);
			me->unconcious();
			destruct(this_object());
			return 1;
    		}   
    }
    else
    {
                 write(HIW "��λ"+RANK_D->query_respect(me)+" δ�����ң���ʲô�װ���\n ����Ц���ԣ����˷�����ô���Ķ�����\n");
                 return 1;
    }
    

}



int do_five()
{
    int cshen;
    int fshen;
    object me;
    me = this_player();

    remove_action("do_one", "1");
    remove_action("do_two", "2");
    remove_action("do_three", "3");
    remove_action("do_four", "4");
    remove_action("do_five", "5");

    cshen = me->query("shen", 1);
    fshen = cshen * -1;

    me->set("shen", fshen);
    if(fshen < 0)
    {
    
    		message_vision(HIY "ԭ��һ���������񣬹ŵ��ȳ���������$N ���Է�����\n����֮�󣬻�����ħ����㣬�����һ���޶���������ֻ�뾴��Զ֮�Ĵ�ħͷ��\n" NOR, me);
    }
    else
    {
		message_vision(HIY "$N����һö�����ɵ�����������������һ�㣬�󳹴���\n�Ӵ�ϴ�ĸ��棬���������ˣ��������գ�\n" NOR, me);
  
    }
    me->set("fupldan", "yes");
    me->unconcious();
    destruct(this_object());

    return 1;
}


int do_six()
{
    object me;
    me = this_player();
    message_vision(HIY "��Ϊ���ǵ�������ÿ��ֻ�ܷ���һ�Σ�$N����ȡ�������ڷ�������������ͷ������������ؼ���ʱ���ٷ���\n" NOR, me);
    return 1;
}
