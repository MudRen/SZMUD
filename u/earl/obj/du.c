inherit ITEM; 
void create() 
{ 
set_name("����",({"du zhu"})); 
set("long","����������Ū�����Ķ���,��֪���ܲ��������⣨�����壩����\n"); 
set("value",10000); 
set("unit","ֻ"); 
} 
void init() 
{ 
if(this_player()==environment()) add_action("do_cure","cure"); 
}
int do_cure()
{
object me;me = this_player();
message_vision("$Nһ�ڽ��������븹��!\n",me); 
me->clear_condition(); 
message_vision("$Nֻ������һ������ֱ͸ȫ����,���ϵľ綾�Ѳ��ٷ�����!\n",me); 
destruct(this_object()); 
return 1; 
} 
