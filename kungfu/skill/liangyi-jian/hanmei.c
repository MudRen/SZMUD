// Code Of ShenZhou 
// ������ - ���ǽ� - ��÷���� hanmei.c  
// by keny

#include <ansi.h> 
#define MAX_INARRAY 5 
#define MIN_INARRAY 2 
       
inherit F_DBASE; 
inherit F_SSERVER; 
       
string *ran_msg = ({ 
"��ͷ���ۣ������Ĳ������ң�ԭ����һ�ס�ȸ����", 
"����Զ����������˼������֮����ϡ��һ�ס����¡�", 
"���ٰ��ң�����һ�ס����¡�", 
}); 
       
string *ran_color = ({ HIC, HIG, HIY, HIR, HIM }); 
       
private string location(string direct); 
void check_fight(object leader); 
private void reset_effect(object *inarray, int partner, int ori_effect, int skill); 
private void remove_effect(object inarray, int skill); 
void random_msg(object leader); 
       
int perform(object me) 
{ 
int skill, ori_effect; 
int partner, num; 
int user_num; 
object victim, weapon; 
object leader, *obj, *inarray, env; 
object *user_list; 
string id; 
           
leader = 0; 
inarray = ({0, 0 , 0, 0, 0, 0}); 
           
if( me->query("family/family_name") !="������") 
return notify_fail("�㲻�������ɵ���ˣ�����ʲô�� \n"); 
                       
if( (int)me->query_temp("hanmei") )  
return notify_fail("���Ѿ��ں�÷�����ڡ�\n"); 

if( me->query_skill("sword") < 100 ) 
return notify_fail("������ǽ�����û�����������˺�÷����ľ�Ҫ��\n"); 
       
if( me->query_skill("dodge") < 100 ) 
return notify_fail("���̤ѩ�޺ۻ�û�����������˺�÷����Ĳ�����\n");

if( !victim ) victim = offensive_target(me); 
       
if( !victim || !victim->is_character() || !me->is_fighting(victim) ) 
return notify_fail("��÷����ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
       
if( victim->query("family/family_name") == "������" )  
return notify_fail("�㷢����ѽ����ʲôҪ���Լ���ͬ��������\n");  
               
if( me->query_skill_mapped("sword") != "liangyi-jian" || !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword" )     
return notify_fail("�㲻�����ǽ������������º�÷����ѽ��\n"); 
env = environment(me); 
obj = all_inventory(env); 
num = sizeof(obj); 
partner = 0;        
              
for( int i = 0; i < num; i++ ) { 
if( obj[i]->query_temp("hanmei") ) { 
if( !leader ) { 
if( obj[i]->query_temp("hanmei/is_leader") == -1 ) 
leader = obj[i]->query_temp("hanmei/data"); 
else 
leader = obj[i]; 
victim = leader->query_temp("hanmei/data")[0][MAX_INARRAY]; 
} 
partner++; 
} 
} 
                        
if( partner == 0 ) { 
inarray[0] = me; 
inarray[MAX_INARRAY] = victim; 
                                 
message_vision(HIG"$N�ֳ�"+(me->query_temp("weapon"))->query("name")+HIG"ָס$n���ȴ��������ɵ�������ʹ�������ɵ�"+HIM"����÷���󡯡�\n" NOR, me, victim); 
                      
user_list = users(); 
user_num = sizeof(user_list); 
             
while( user_num-- ) { 
if( !environment(user_list[user_num]) ) continue; 
if( user_list[user_num]->query("family/family_name") != "������") continue; 
if( environment(user_list[user_num]) == env ) continue; 
if( !living(user_list[user_num]) ) continue; 
if( location(file_name(env)) == location(file_name(environment(user_list[user_num]))) ) 
tell_object( user_list[user_num], HIG"��·�����" + me->query("name") + "������׼���ú�÷����Ը�" + victim->query("name") + "��" + "\n�����������" + env->query("short") + "��\n\n"NOR ); 
else  
tell_object( user_list[user_num], HIG"��·�����" + env->query("short") + "�����ı���Ӳ����������������" + env->query("short") + "������\n\n"NOR );  
}  
                              
partner = 1; 
skill = me->query_skill("sword"); 
                      
for( int i=0; i < num; i++) { 
if( obj[i] == me ) continue; 
if( !living(obj[i]) ) continue; 
if( !obj[i]->is_character() || obj[i]->is_corpse() ) continue; 
if( !obj[i]->is_fighting(victim) ) continue; 
if( obj[i]->query_skill_mapped("sword") != "liangyi-jian" ) continue; 
if( !objectp(weapon = obj[i]->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword" ) continue;  
if( !obj[i]->is_fighting(victim) ) continue;                                              
if( (int)obj[i]->query_temp("hanmei") ) continue;               
                              
inarray[partner] = obj[i]; 
message_vision(HIY"$Nһ�߳���˵��������Ȼͬ�����ѣ��ҾͰ���һ�Ѱɡ���" + "˵��һ�߰�Χ��$n��\n" NOR, inarray[partner], victim );  
skill += inarray[partner]->query_skill("sword"); 
partner++; 
if( partner == MAX_INARRAY ) break; 
} 
                     
me->set_temp("hanmei/is_leader", 1); 
me->set_temp("hanmei/data", ({ inarray, skill, partner }) ); 
                     
skill = (int)(skill / (partner*3)); 
if( partner > 1 ) { 
for( int i = 0; i < partner; i++ ) { 
inarray[i]->add_temp("apply/dodge",  skill ); 
if( i > 0 ) { 
inarray[i]->set_temp("hanmei/is_leader", -1); 
inarray[i]->set_temp("hanmei/data",  me ); 
} 
} 
} 
            
call_out("random_msg", 3, me); 
            
me->start_call_out( (: call_other, __FILE__, "check_fight", me :), 1); 
     
} 
              
else if( partner >= MAX_INARRAY )  
return notify_fail("��÷����ֻ�ܹ��ɶ�������ʩ����\n"); 
      
else { 
inarray = leader->query_temp("hanmei/data")[0]; 
skill = leader->query_temp("hanmei/data")[1]; 
ori_effect = (int)(skill / (partner*3)); 
if(partner == 1)  
leader->add_temp("apply/dodge", ori_effect ); 
me->add_temp("apply/dodge", ori_effect ); 
inarray[partner] = me; 
partner += 1; 
skill += me->query_skill("sword"); 
leader->set_temp("hanmei/data", ({ inarray, skill, partner }) ); 
reset_effect(inarray, partner, ori_effect, skill);       
me->fight_ob(victim); 
victim->fight_ob(me); 
me->set_temp("hanmei/is_leader", -1); 
me->set_temp("hanmei/data", leader); 
message_vision(HIG"$Nһ�߳����ȵ������󵨵Ķ�����Ȼ���˺��������ص��ӡ�" + "һ�߼��뺮÷����һ�߰�Χ$n��\n" NOR, me, victim );  
for( int i = 0; i < partner-1; i++ ) 
tell_object(inarray[i], HIG"\n�㿴����ͬ�ż��룬���ɵ��˷�������\n"NOR);
} 
      
return 1; 
} 
      
private string location(string direct) 
{ 
int start, end, count, next; 
      
while (count != 3) { 
if( direct[next] == '/' ) count++; 
if (count == 2 && start == 0)  
start = next+1; 
next++; 
} 
end = next-2; 
direct = direct[start..end]; 
return direct; 
} 
      
void check_fight(object leader) 
{ 
object weapon, *inarray; 
int partner, skill, ori_effect, ori_partner; 
              
if( !leader->query_temp("hanmei") ) return; 
              
inarray = leader->query_temp("hanmei/data")[0]; 
skill = leader->query_temp("hanmei/data")[1]; 
partner = leader->query_temp("hanmei/data")[2]; 
ori_effect = (int)(skill / (partner*3)); 
ori_partner = partner; 
         
if( !living(inarray[MAX_INARRAY])  
|| !present(inarray[MAX_INARRAY]->query("id"), environment(leader))  
|| inarray[MAX_INARRAY]->query("qi") <= 50  
|| !leader->is_fighting(inarray[MAX_INARRAY])  
|| leader->query_skill_mapped("sword") != "liangyi-jian" 
|| !objectp(weapon = leader->query_temp("weapon"))  
|| (string)weapon->query("skill_type") != "sword" )   
{ 
if ( partner != 1 ) { 
for ( int i = 0; i < partner; i++ ) 
remove_effect(inarray[i], ori_effect); 
if (living( leader )) 
message_vision(HIB"$N��һ������ɢ�󣡡���������ɢ����ɢ��ɢ��\n\n"NOR, leader); 
else 
message_vision(HIM"���˿���$N��ȥ���ٴ���ȥҲû��ʲô��˼��������ɢȥ��\n\n"NOR, leader); 
} 
else { 
leader->delete_temp("hanmei"); 
if ( living(leader) ) 
message_vision(HIM"$N����û��ͬ�ż��룬�ĸ��˼�û�飬ɢ���˺�÷��λ��\n\n"NOR, leader);
} 
return; 
} 
                
else { 
for ( int i = 1; i < ori_partner; i++ ) { 
if ( inarray[i] == 0 ) break; 
if ( !inarray[i]->is_fighting(inarray[MAX_INARRAY])  
|| inarray[i]->query_skill_mapped("sword") != "liangyi-jian" 
|| !objectp(weapon = inarray[i]->query_temp("weapon"))  
|| (string)weapon->query("skill_type") != "sword" )  
{ 
message_vision(HIG"$Nһ��˵��������Ͷ�л��λͬ�ŵİ��������ձض��𱨡���" + "һ��˵һ���˳��˺�÷����\n"NOR, inarray[i]);  
remove_effect(inarray[i], ori_effect); 
skill -= inarray[i]->query_skill("sword"); 
partner -= 1; 
if( i != partner ) {                       
inarray[i] = inarray[partner]; 
inarray[partner] = 0;                    
i--; 
} 
                          
else inarray[i] = 0; 
} 
} 
                  
if( ori_partner != partner ) { 
leader->set_temp("hanmei/data", ({inarray, skill, partner})); 
reset_effect(inarray, partner, ori_effect, skill);               
} 
} 
          
call_out("check_fight", 1, leader); 
} 
      
private void reset_effect(object *inarray, int partner, int ori_effect, int skill) 
{ 
skill = (int)(skill/(partner*3)); 
              
if(partner == 1)  
{ 
inarray[0]->add_temp("apply/dodge", -ori_effect ); 
return; 
} 
              
else { 
for( int i = 0; i < partner; i++ ) 
{ 
if(inarray[i] == 0 ) break; 
inarray[i]->add_temp("apply/dodge", -ori_effect ); 
inarray[i]->add_temp("apply/dodge", skill ); 
} 
} 
} 
      
private void remove_effect(object inarray, int skill) 
{ 
inarray->add_temp("apply/dodge", -skill ); 
inarray->delete_temp("hanmei"); 
} 
      
void random_msg(object leader) 
{ 
int partner; 
int ran; 
int ran_usr, ran_usr1; 
object obj, obj1, victim, weapon; 
              
if ( !leader->query_temp("hanmei/data") ) return;
if( partner = leader->query_temp("hanmei/data")[2] ) { 
if(random(5) < 2) { 
if( partner > 1 ) { 
ran_usr = random(partner); 
obj = leader->query_temp("hanmei/data")[0][ran_usr]; 
ran = random(5); 
message_vision( ran_color[ran] + "$N�ں�÷������" + ran_msg[ran] + "\n" NOR, obj); 
victim = leader->query_temp("hanmei/data")[0][MAX_INARRAY]; 

if ( random(2) == 1 ) { 
if( obj->query_skill_prepare()["strike"] == "kunlun-zhang" ) { 
message_vision(ran_color[ran] + "$N������䣬���ƹ���$n��\n"NOR, obj, victim); 
weapon = obj->query_temp("weapon"); 
COMBAT_D->do_attack(obj, victim, weapon, 1); 
COMBAT_D->do_attack(obj, victim, weapon, 1); 
obj->delete_temp("weapon"); 
obj->set_temp("action_flag",1); 
COMBAT_D->do_attack(obj, victim); 
COMBAT_D->do_attack(obj, victim); 
obj->set_temp("weapon", weapon);
obj->set_temp("action_flag",0); 
if ( obj->query("neili") >= 150 ) obj->add("neili", -10); 
}
}

else {   
do { 
ran_usr1 = random(partner); 
} while ( ran_usr1 == ran_usr); 
                                          
obj1 = leader->query_temp("dagou/data")[0][ran_usr1]; 
message_vision(ran_color[ran] + "$N��$nð��ʹ�����ؿ콣��˫���ϱڣ������޵С�\n"NOR, obj, obj1); 
COMBAT_D->do_attack(obj, victim, obj->query_temp("weapon"), 1); 
COMBAT_D->do_attack(obj, victim, obj->query_temp("weapon"), 1); 
obj1->set_temp("action_flag", 1); 
COMBAT_D->do_attack(obj1, victim, obj1->query_temp("weapon"), 1);
COMBAT_D->do_attack(obj, victim, obj->query_temp("weapon"), 1);  
obj1->set_temp("action_flag", 0); 
if ( obj->query("neili") >= 150 ) obj->add("neili", -5); 
if ( obj1->query("neili") >= 150 ) obj1->add("neili", -5); 
} 
} 
else 
message_vision( ran_color[ran] + "$N��Ȼ������ս����������" + ran_msg[ran] + "����������Ӳ��Ӳ���ȴ�֧����\n"NOR, leader);  
} 
                              
call_out("random_msg", 3, leader);
} 
}
