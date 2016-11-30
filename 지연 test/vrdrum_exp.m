
for i=1:6
    Sheet=xlsread('D:\VRDrum\Áö¿¬_1.xlsx',i);
    Sheet=Sheet(2:end,2:end);
    n=1:length(Sheet);
    pos=Sheet(:,1:3);
    arm=Sheet(:,4:6);
    vel=Sheet(:,7:9);
    ang=Sheet(:,10:12);
    vel_head=vel+cross(ang,arm).*0.37033;
    accel_head=vel(2:end,:)-vel(1:end-1,:);
    subplot(3,2,i);
    %plot(n,pos(:,2),n,vel_head(:,2),n,[0;accel_head(:,2)]);
    plot(n,vel_head(:,2));
end