//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//********************   Menpai QUESTION Star Here   **************************
//*****************************************************************************
//*****************************************************************************
//*****************************************************************************

void menpai_question(object me, string strName, string strId, string strFName, int intExp)
{
        object npc;
        string strMsg, answer, qn;
        int r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16;
        r1 = random(5) + 5;
        r2 = random(5) + 10;
        r3 = random(5) + 15;
        r4 = random(5) + 20;
        r5 = random(5) + 25;
        r6 = random(5) + 30;
        r7 = random(5) + 35;
        r8 = random(5) + 40;
        r9 = random(5) + 45;
        r10 = random(5) + 50;
        r11 = random(5) + 55;
        r12 = random(5) + 60;
        r13 = random(5) + 65;
        r14 = random(5) + 70;
        r15 = random(5) + 75;
        r16 = random(5) + 80;


        switch(random(270))
        {
	        case 0:
                {
                        strMsg = HIW"һ�����ӿ첽�߹���������˵����������������������������¾�����Ҫ�����������\n"NOR;
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r1+" * "+r2+" * "+r3+" * "+r4+" * "+r5+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r6+" *  1 *  4 *  7 * "+r16+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r7+" *  2 *  5 *  8 * "+r15+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r8+" *  3 *  6 *  9 * "+r14+" *\n";
                        strMsg = strMsg + "**************************\n";
                        strMsg = strMsg + "* "+r9+" * "+r10+" * "+r11+" * "+r12+" * "+r3+" *\n";
                        strMsg = strMsg + "**************************\n";

                        answer = "2t"+r10+" "+r10+"t"+r16+" "+r16+"t1 1t9";

                        tell_object(me, strMsg);
                        tell_object(me, HIW"������ĳ���ɵ����Σ����Ҫ�ƽ�������������ڽ�һ����ȫ������\nһ����������Ͳ��������ˣ�������ʮ���ʱ��˼��"NOR);
                        tell_object(me, NOR"\n�ش𷽷�ʹ�õ�Ե㷽ʽ�������һ������Ȼ����������Ȼ�������������ߵ�һ��ָ��Ϊ ans 1t3 3t9 9t7 7t1��\n"NOR);
                        tell_object(me, NOR"��������ش� (��ʼֱ�� 2)\n"NOR);
                        qn="֪ʶ�ʴ���";
                        break;
                }
                case 1:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��Ц����������������̵���ʹ��˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 2:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ʯ������������Ǵ����������?  ans ��Ʒ��\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ձ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 3:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС�����Ķ�����?  ans ������\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����Ժ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 4:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ӹ��ԭ����ʲô?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 5:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ӹ���һ������С˵����һ��?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "¹����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 6:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����м�������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "5";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 7:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС��Ȣ�˼�������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "7";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 8:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����ڡ����Ӣ�۴���������ŷ�����߶��ĵ��������м���?  ans ��������\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 9:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������һ��ʼ��˭Ϊʦ?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����߹�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 10:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �黨����ʲôҩ�ɽ�?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ϳ���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 11:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���ص��ɷ���˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 12:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���߹��Ի��صĵ�һ����ʲô?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ռ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 13:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����Ȣ�����ǹ��Ĺ���?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 14:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ˭���������̻��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ʯ����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 15:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��һ������ô����?  ans һ����\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 16:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ڶ��λ�ɽ�۽�˭������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ŷ����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 17:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����ĸ����˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 18:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����õ���ʲô����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 19:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����Ӣ�۴����й����������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��Ѫ����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 20:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����Ӣ�۴��������˵������˭? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ʮ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 21:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����Ͱ�����ʲô��ϵ?  ans ������\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 22:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������ܵ�������ʲô?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�廨��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 23:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������˭���ϵ�? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ܽ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 24:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����Ⱥ���˭��ɱ? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 25:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "Ҷ����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 26:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������һ�ɵĴ�ʼ��?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 27:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��Ц�������������ȳ������� \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ƽ֮";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 28:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����ѩ�������¹��Ц�������б�ԧ����˵�˼�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "14";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 29:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������ɹ��Ǻι�ְ? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��Ժ����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 30:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������˲����С�����ѧ��֮�ˣ���һ������ɱ�޹�����仰����˭��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�Ƿ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 31:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������ʦ����˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�߶�����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 32:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����Ǻ��ɵ���?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��Ĺ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 33:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������˭ѧ����¾Ž���?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 34:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��а��˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ҩʦ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 35:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ƽ֮�Ҵ�������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��а����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 36:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ˭�⿪���������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 37:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ƺ�������˭?  ans ��������������ʹ����ǰ\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ͷ�Ӻ���ǧ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 38:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ǧ�����أ�һͳ����������һ�ɵ��п�?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 39:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������е�ʯ���죬��˭�Ķ���?  ans �������������е���ǰ\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ʯ�������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 40:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ӹ14��С˵���ǵ�һŮ���ǵ����ı�? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����Х����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 41:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС�������ݼ��г��ö���������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������ʮ����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 42:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����ʮ���¾���������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "8";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 43:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС����������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 44:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����ʦ����˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "С��Ů";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 45:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��������������˭����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 46:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС����˭�ϱ�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "éʮ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 47:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������׽��˭����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��֤";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 48:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���ݵĵ���˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ҩʦ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 49:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��а��ָ˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ҩʦ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 50:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ԧ��˫����һ�̡����ߡ���һ����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�޵�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 51:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����Ⱥ������ô�ڹ�?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ϼ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 52:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������90������ʱ������һλ���ӱ������ֽ�? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 53:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����������ô����? ans ������\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ɱ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 54:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ҹ�����һ���м���?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "6";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 55:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����Ĺù���˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "С��Ů";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 56:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������м�������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "7";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 57:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���ɽ���ʲô���������岹Ѫ? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ˮ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 58:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������Ⱥ���ᡰ����������֮λ����˭? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 59:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����߹�֮����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 60:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ˭�����ˡ����һ�������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ܲ�ͨ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 61:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����ͻ��ع��м���Ů��?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "2";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 62:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����ѩ�������¹��Ц�������б�ԧ���С�����ָ����ʲô?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���Ǿ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 63:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��Ȼ��������˭����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 64:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��¹���ǡ������˹���˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ΤС��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 65:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����������ػ��ĸ��õ�����?  ans ����������\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��˳�ú�������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 66:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����Ⱥ�����ӽ���ô����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 67:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��һ������������书������˭? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 68:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��������������ڤ���Ϸֱ���? ans ����������������ǰ\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ױ��̺�¹�ȿ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 69:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����Ӣ�۴���������ŷ������ʹ����һ�ֶ�ҩɱ���е�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ʬ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 70:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ɽ��һ�߹��еĳ����ԭ������ô? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��һ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 71:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ˳���ڸ������ġ���ʮ���¾�����ҳ��д�˾���ô��?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����Ӹ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 72:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ¹�ȿ͵������������ô?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ɫ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 73:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���Ʒ������ʹ���������ô��������?  ans ����������������һ��ͨ�׵�����\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 74:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��һ�����ӵı�����ӵ�ɽׯ����ô����?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���ɽׯ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 75:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���ҵĵڶ���������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 76:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����ɱ�˼�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "3";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 77:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������������ؤ���Ʋ���ͷ������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 78:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����׶�ж೤? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 79:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ɽ�۽�ǰ�����߹��Գ���ƽɱ��������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "231";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 80:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��Դ˼Ӣ�����Ͱ������ţ�ѩ½�ı�����仰�������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����澭";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 81:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���Ӣ��ר����д���������ȭ���ǣ�  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����ȭ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 82:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ڶ��λ�ɽ�۽��У�ŷ����ҧ�˻�ҩʦʲô��λ?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����ʳָ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 83:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������Ĳ�С˵�е�����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���Ӣ�۴�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 84:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��������ǧ�ɣ���������ʲôѨ��?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ͻѨ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 85:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������ű����½��ε���������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 86:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : Ц����������ƽ֮��ʲô�ھֵ�? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����ھ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 87:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������˲������룬����������ɽ��ѧ���Ĺ�����ʲô? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�貨΢��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 88:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ؤ�ﷶ��������ʲô����ץ����ͷ�ͻ�?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��צ������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 89:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��������´��ʡ���˭�Ľ���? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���˷�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 90:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����ĵ�ʦ����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 91:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������´����˾���ǣ�\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����ʯ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 92:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������¶����ĸ�Ѩλ������������ס������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���Ѩ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 93:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���屻�ɹ��ʵ������������ж���ʿ������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "100";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 94:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������ʿ������ʲô����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ì";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 95:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����˲��������Źص��ξ�������ʲô? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 96:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : лѷ��������˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���޼�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 97:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ÷������˭��ͽ��?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ҩʦ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 98:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ˭һֱ�����������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 99:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ҩʦ�Ĵ������˭? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "½�˷�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 100:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������һ��ɱ��������˭��  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 101:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��Х���Ǳ�˭ɱ���ģ�\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 102:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ½��Ӣ��˭�Ķ��ӣ�\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "½�˷�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 103:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����㼸��ʧȥ��ĸ? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "8";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 104:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������ķ���Ĳ�С˵�е�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����Х����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 105:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������һ�δ��ﲮ�⣬�õ���ʲô��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 106:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������Ĳ�С˵�е�����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ɺ��⴫";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 107:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����Ӣ���Ǹ����ɵĸ���? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 108:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ҹ�����ɱ����ץ���˵���֫��̧�����˺���ķݣ���������̧�������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "10";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 109:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������ʲô?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 110:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : Ī�������Ľ�����ʲô������?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 111:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������һ���Ǻ�ɽ�ɵ�������ҩ?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 112:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����������̵�ʲô��?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "үү";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 113:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ȫ�����м����쾦���?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "2";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 114:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ֹ��ĸ����ʲô?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "Ѧ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 115:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����˲��������������µĵڼ�������?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����ʮ�ߴ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 116:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����˲��а��̵�ʦ���ǣ� \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 117:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ºš�С��а������?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 118:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������Ĳ�С˵�е�����?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 119:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����������У��������޺���������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ɫ��ʦ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 120:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������������ũ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���³���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 121:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : лѷ��һ�γ�������������ʲô����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 122:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����ó�ʲô����?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 123:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ľ����������������ʲô?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��õ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 124:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����������µ���ҵ��ʦ��˭?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 125:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : һ�ƴ�ʦ��ͽ����λ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���Ը���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 126:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����ù���˵�˼�������Ӣ�ۡ�?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "5";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 127:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��β�����˭����?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 128:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ȶ���ʦ��?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ǧ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 129:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������˹��弸֧����?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "3";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 130:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������������ļ�֧����?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "3";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 131:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������ĵڶ���������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�̻�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 132:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���ַ�����˵�Լ��ķ���?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 133:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �߸������У�ΤС�����Ƚ�ʶ����˭? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�彣��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 134:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС�����߸�����֮�У����̬����? ans �ĸ���\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 135:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС�����߸�����֮�У�����˳��������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "˫��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 136:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ڤ�����������޼����ϵ���ӡ��ʲô��ɫ��?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 137:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��������������̡����Ĳ�С˵�е��½�?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 138:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������������д�����������ֺ�����?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 139:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������ף��ײؼ�����仰��˭����?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "С��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 140:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���޼ɴ�Ӧ�����ĵ��������ǣ�\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ü";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 141:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ۺ������ĸ�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ຣ����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 142:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������쵶��ʲô?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 143:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ɱ���ᡱ�ġ��ꡱ��ָ?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 144:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��̫��ĸ��׽�?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ë����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 145:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ͷ�ӱ��ݵ�ԭ���Ƿ�����ʲôҩ��?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��̥�׽���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 146:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������˭��Ů���� \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���Գ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 147:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����������ж����ɾ��ֱ����ж������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "12";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 148:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���̺���������ʹ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ԫ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 149:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������������ػ���Ů�Ӿ�лѷʱ���˼������?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "8";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 150:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��������˷�����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 151:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���Ǹ��»���Ӱ���Ĳ�С˵�е�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ԧ�쵶";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 152:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ʷ�ڵ���˭�ı���?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ʯ����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 153:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����ѩɽ�ɡ�����ӭ�͡���������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����Ҿ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 154:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��½���ཻ�ֵ�����ʹ��ʲô����?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ֱ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 155:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �䵱��ȭ���ж���ʽ? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "32";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 156:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���˷����ɶ�������һ���ںδ�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 157:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����������������మ? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ݾ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 158:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����������ǡ��д��������ɵ���?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 159:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ˭��һ�������޼��书?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�Ŵ�ɽ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 160:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��һ�λ�ɽ�۽�˭ʤ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 161:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : Ц����������ɽ���ɺ���������˭?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "½��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 162:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����־�Ǻ�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 163:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ض���ħ��������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 164:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������Ǹ�ʲôְҵ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ʦ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 165:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������ʹ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�⾢��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 166:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��������о�����˭����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��Ħ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 167:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������ĸ���λ����������?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����Ȫ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 168:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ɽ�Ż�������ʲô�Ʒ�? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "Τ����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 169:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��Զɽ��һ��Ǳ�������£�͵�����书��?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����ָ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 170:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��������¡���һ���У�½��˫�ͳ�Ӣ�������ġ��ֲ�������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����ͨ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 171:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ħ����λ��������ǰ�ڻ�ɽ˼�����Ͽ��˾��ƺ�ɽ����������? ans ����������������ǰ\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���ɺ��Ժ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 172:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������ɹ���ʲô���? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 173:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����˲���ʲô�ڽ̵�����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 174:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���黿�����Ǻ�������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 175:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������ʥ�ɼ��������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "1";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 176:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���޼ɳ������ĸ�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 177:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ĸ�����˭? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 178:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���콣�в����Ĳ���ѧ�ؼ� \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����澭";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 179:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : С��Ů��ʦ����˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ֳ�Ӣ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 180:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ޱ�������³����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����ɽ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 181:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ָ�ʹ���ȫ��������˭���书?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "̷����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 182:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������˭�� \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 183:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���һ�Ӱ����񽣡�����һ����ʲô?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�̺�����������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 184:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ƺ��Ĺ���˭��һ������\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 185:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ﲻ���ĵ���������ʲôͼ�Σ�  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 186:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����Դ������Ͼ�ѧ����ʲô?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��Ȼ������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 187:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������һ�ɵ�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ɽ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 188:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������������һ���г���? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 189:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : Ľ�ݸ����Ĺ�����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 190:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����������ֱ���˭���ε�?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����ʵ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 191:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ˭��ؤ�������ɵĳ���?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "³����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 192:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ǧ���ʦ����˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�Ϲٽ���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 193:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ɽ�ɹ����˼���Ů����?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "7";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 194:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����Ⱥס����ʲô? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������Ϊ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 195:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ɽ�ɵ��Ľ���ʲô? ans �ĸ��֣��ĸ���\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ͬ�ż��ʣ������ɱ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 196:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ˭ɱ����Ω�ҽ���? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�´�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 197:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����������̼ұ�������������˭ָ������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�԰�ɽ   ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 198:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС�������־����ʲô? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����Ժ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 199:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������ȭ����˭����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ܲ�ͨ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 200:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ƽ֮���⹫��˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��Ԫ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 201:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����ͻ���һ���ж��ٸ���Ů? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "3";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 202:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС�����������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                            answer = "Τ����"; 
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 203:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���� �� Ӣ �� ����С˵�����˵������˭? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ʮ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 204:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �Ŵ�ɽ��������ĵڼ�����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "5";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 205:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : Ү�ɺ��������ΪʲôԪ˧?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ƽ�ϴ�Ԫ˧";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 206:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����ġ�������ʲô��˼?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��֮";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 207:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���к����Ĵ���˵��ϼ�? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "4";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 208:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��Ҫ���⣬�ܵ�������У�Ҫ�����ܵ��в�ɿ�������˭˵��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 209:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : Ԭ��־�ĵ�һ��ʦ����˭? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 210:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ڡ�������¡��У�����ֹ�������˵��Ů����������ô?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 211:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��һ�λ�ɽ�۽��͵ڶ��λ�ɽ�۽��������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "25";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 212:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������ʱ�ڵ���ɽ�ɹ��м�·����?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "17";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 213:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����������ɺ����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "8";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 214:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ʷ�����Ἰ�н���ʮ����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "12";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 215:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ɽ�����ƺ�ɽ�ɽ�����ħ�̳�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 216:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������ǣ������������ı����ϵ�? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����˲�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 217:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ϣ�����Ĳ�С˵�е�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ɺ��⴫";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 218:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����С��Ů�������δ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "16";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 219:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������˲����С��޶�����ָ�����Ĵ�����е�˭?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "Ҷ����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 220:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����߹���Ψһ��Ů��������˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��СӨ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 221:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �𴦻��뽭���߹��ںδ�����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����¥";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 222:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������������书? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�䵱";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 223:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��������˭��ͽ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 224:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : Ҫ����ô�����ֻ����ĺ���?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 225:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : Ѫ�������Ǳ�˭ɱ����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 226:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ʯ��������ֹ���?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "̫����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 227:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����ʮ���Ƶ�һʽ��?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����л�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 228:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����������У��������ɺ�̫��ķ�����˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 229:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������ͯ���Դ����书��ʲô?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���һ�����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 230:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������������ɱ�����ɹſɺ���? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ɸ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 231:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������ʲô���ɵ�����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ң��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 232:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���㹫������ô����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ɱ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 233:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ÷�����Ǳ�˭������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ŷ����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 234:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ܲ�ͨ���ĸ����ɵ�? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ȫ���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 235:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����Ⱥ�ı�а������˭������? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ѧ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 236:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ϵۺͶ�а�ֱ���˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "һ�ƺͻ�ҩʦ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 237:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������ĸ�����˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 238:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС�����˭?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "֣��ˬ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 239:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��������������˭?  ans ������\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 240:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���˷�ͺ���һս˭ʤ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��֪��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 241:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ȫ��������˭���书���?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�𴦻�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 242:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ϵ۵�ԭ����ʲô? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 243:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������Ǳ�˭ɱ����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 244:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ÷���������õ���������ô�ڵ�?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��һ��������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 245:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����һ���м���ʦ��?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "9";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 246:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��һ��ָΪ�������ˣ��������书��ʧ?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "5";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 247:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ��ƽ֮�������ʲô?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "Сѩ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 248:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������׺���ס�ĵ��۽�ʲô? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�ɷ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 249:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����ڻ�ɽ���ڵ����������ڼ�? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "3";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 250:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������ѡ����һ��ʱ��ϴ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ʱ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 251:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������ĸ�׵ĵ�����ʲô?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����ɢ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 252:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����������ɽ��ѧ��һ�����˹������书��ʲô?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ڤ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 253:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����ĸ���Ľ�ݸ�������һƷ��ʱ�Ļ���?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 254:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������߳�ʯ��������Ĵ���Ů����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��Ӣ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 255:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ������������˭������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����ֹ";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 256:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����ƭ����Ϻ����Ἰ������ԭһ��?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "16";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 257:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �ɹž��������ʱ����ʱ�Ĵ�������?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 258:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ˭ɱ����Ħ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 259:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���һ����Ү������ս����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 260:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �����Ǳ�˭ɱ��? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 261:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ɱ��������ʷ�ɵ���˭? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "ΤС��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 262:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС��ɱʷ���õ���ʲô����? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "��ʯ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 263:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС�����ȸ�˭ѧ������\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "���Ϲ�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 264:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������׵����Ϊ? \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "˳��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 265:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ΤС�����߸�����֮�У����������?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 266:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : �������ĸ��µ�����?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "������";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 267:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ˳�γ��Һ�ķ���Ϊ?  \n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "�г�";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 268:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ����ү�Ķ����ӽ�֣��ˬ����ô������?\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "֣��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                case 269:
                {
                        strMsg = HIW"���һ��ʦ�ܷ糾���͵��ܵ�����ǰ���˸�Ҿ���Ϲ��Ͼ����ʵ����������������������������\n"NOR;
                        strMsg = strMsg + "\n���� : ���������ɽ������������������?  ans ��������+��+��������\n";
                        strMsg = strMsg + "���棺����Բ�Ҫ�ڹ���Ƶ����̸�۴��⣬����й©���ɻ��ܡ�\n";
                        answer = "����ʮ��";
                        qn="֪ʶ�ʴ���";
                        tell_object(me, strMsg);
                        tell_object(me, NOR"�������� ans <��> ���ش𣬱��� ans 3 ���� ans ������\n"NOR);
                        break;
                }
                
	}
        me->start_busy(3);
        npc = new("/family_job/ansnpc");
        npc->set("aid", me->query("id"));
        npc->move(environment(me));
        npc->set("correctans", answer);

        CHANNEL_D->do_channel(this_object(), "alarm", sprintf("����Ŀ��: %s(%s)  ����NPC: %s  ������̬: �ǻ�������  ��Ŀ���: %s", me->query("name"), me->query("id"), npc->query("name"), qn));
        return;
}
